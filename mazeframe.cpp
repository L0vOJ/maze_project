#include<iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <math.h>
#include "mazeframe.h"
using namespace std;

#define up field[y-1][x]
#define down field[y+1][x]
#define left field[y][x-1]
#define right field[y][x+1]
#define me field[y][x]

#define ct_wall_len ((width-3)/2) 
#define ct_void_len ((width-1)/2) 

block** field_make(block** field,int width);
block** block_init(int width);
block** rand_wall(block** field,int width);
block** root_link(block** field,int width);
block** root_chain(int y,int x,block**field);
block** root_pruning(block** field,int width);
block** root_plus(int y,int x,block**field);
block** void_seed(block** field,int width);
block** void_chain(int y,int x,block**field);
block** void_pruning(block** field,int width);
block** void_plus(int y,int x,block**field,int width);

void mazeframe::ckeckfield(){
	string wallicon;
	for(int y=0;y<width;y++){
		for(int x=0;x<width;x++){
			wallicon = mode?(me.wall?"■  ":"   "):(me.wall?"■ ":"  ");
			cout<<wallicon;
		}
		cout<<endl;
	}
}

mazeframe::mazeframe(){
	width=5;
	width = width*4+1;
	mode = 1;
	field = field_make(field,width);
}

mazeframe::mazeframe(char** argv){
	width=5;
	width = width*4+1;
	mode = strcmp(argv[1],"-n")?1:0;
	field = field_make(field,width);
}

block** field_make(block** field,int width){
	field = block_init(width);
	field = rand_wall(field,width);
	field = root_link(field,width);
	field = root_pruning(field,width);
	field = void_seed(field,width);
	field = void_pruning(field,width);
	return field;
}

block** block_init(int width){
	block** field = new block*[width];
	for(int step=0;step<width;step++){
		field[step]=new block[width];
	}
	for(int x=0;x<width;x++){
		for(int y=0;y<width;y++){
			me.wall = (x==0||y==0||x==width-1||y==width-1)?1:0;
		}
	}
	for(int y=0;y<width;y+=2){
		for(int x=0;x<width;x+=2){
			me.wall=1;
		}
	}
	return field;
}

block** rand_wall(block** field,int width){
	srand(time(0));
	int x,y,tap=0;
	while(1){
		x=(1+rand()%(width-2));             
		if(x%2){                        
			y=2*(1+rand()%(ct_wall_len));  
		}
		else{
			y=1+2*(rand()%(ct_void_len)); 
		}
		if(me.wall==0){ 
			tap++;
		}
		me.wall=1;
		if(tap>=(pow(width,2)-pow(ct_void_len,2)-pow(ct_wall_len,2))/3){
			break;
		}
	}
	return field;
}

block** root_link(block** field,int width){
	for(int line=0;line<width;line+=2){
		field[0][line].root=1;
		field[line][0].root=1;
		field[width-1][line].root=1;
		field[line][width-1].root=1;
	}
	for(int line=2;line<width-1;line+=2){
		if(field[1][line].wall==1){
		    field[2][line].root=1;
		    field = root_chain(2,line,field);
		}
		if(field[width-2][line].wall==1){
		    field[width-3][line].root=1;
		    field = root_chain(width-3,line,field);
		}
		if(field[line][1].wall==1){
		    field[line][2].root=1;
		    field = root_chain(line,2,field);
		}
		if(field[line][width-2].wall==1){
	    	field[line][width-3].root=1;
		    field = root_chain(line,width-3,field);
		}
	}
	return field;
}

block** root_chain(int y,int x,block**field){
	if(up.wall==1){
		if(field[y-2][x].root==0){
			field[y-2][x].root=1;
			field = root_chain(y-2,x,field);
		}
	}
	if(right.wall==1){
		if(field[y][x+2].root==0){
			field[y][x+2].root=1;
			field = root_chain(y,x+2,field);
		}
	}
	if(down.wall==1){
		if(field[y+2][x].root==0){
			field[y+2][x].root=1;
			field = root_chain(y+2,x,field);
		}
	}
	if(left.wall==1){
		if(field[y][x-2].root==0){
			field[y][x-2].root=1;
			field = root_chain(y,x-2,field);
		}
	}
	return field;
}

block** root_pruning(block** field,int width){
	srand(time(0));
	int pruning_state=1;
	int arrange_y;
	while(pruning_state){
		pruning_state=0;
		for(int y=2;y<width-2;y+=2){                //Çà, ¿­¿¡ ÆòÇàÇÏ°Ô »Ì¾Ò´Âµ¥, ´ë°¢¼±À¸·Î °Ë»öÇØº¸µµ·Ï ÇÏÀÚ
			for(int x=2;x<width-2;x+=2){
				arrange_y = 2 + (y+x-4)%(width-3);          //len-3 =14 -- %ÃÖ´ë=13
				if(field[arrange_y][x].root==0){
					field = root_plus(arrange_y,x,field);
					pruning_state++;
				}
			}
		}       
	}
	return field;
}

block** root_plus(int y,int x,block**field){
	int dice,surround=0;
	dice=rand()%4;                    //printf("%d",dice);
	for(int z=0;z<4;z++){
		switch(dice%4){
			case 0:{    //up
				if(field[y-2][x].root==1){
					up.wall=1;
					me.root=1;          //printf("%d",dice);
					field = root_chain(y,x,field);
					return field;							
				}
				if(up.wall==1){
					surround++;
				}
				dice++;
			}break;
			case 1:{  //right
				if(field[y][x+2].root==1){
					right.wall=1;
					me.root=1;          //printf("%d",dice);
					field = root_chain(y,x,field);
					return field;
				}
				if(right.wall==1){
					surround++;
				}
				dice+=2;
			}break;
			case 2:{  //down
				if(field[y+2][x].root==1){
					down.wall=1;
					me.root=1;          //printf("%d",dice);
					field = root_chain(y,x,field);
					return field;
				}
				if(down.wall==1){
					surround++;
				}
				dice-=2;
			}break;
			case 3:{  //left
				if(field[y][x-2].root==1){
					left.wall=1;
					me.root=1;          //printf("%d",dice);
					field = root_chain(y,x,field);
					return field;
				}
				if(left.wall==1){
					surround++;
				}
				dice--;
			}break;
		}
	}
	if(surround==0){
		switch (dice) {
			case 0:{
				up.wall=1;
			}break;
			case 1:{
				right.wall=1;
			}break;
			case 2:{
				down.wall=1;
			}break;
			case 3:{
				left.wall=1;
			}break;
		}
	}
	return field;
}

block** void_seed(block** field,int width){
	field[(width-3)/2][(width-3)/2].path=1;
	return field = void_chain((width-3)/2,(width-3)/2,field);
}

block** void_chain(int y,int x,block**field){
	if(up.wall==0){
		if(field[y-2][x].path==0){
			field[y-2][x].path=1;
			void_chain(y-2,x,field);
		}
	}
	if(right.wall==0){
		if(field[y][x+2].path==0){
			field[y][x+2].path=1;
			void_chain(y,x+2,field);
		}
	}
	if(down.wall==0){
		if(field[y+2][x].path==0){
			field[y+2][x].path=1;
			void_chain(y+2,x,field);
		}
	}
	if(left.wall==0){
		if(field[y][x-2].path==0){
			field[y][x-2].path=1;
			void_chain(y,x-2,field);
		}
	}
	return field;
}

block** void_pruning(block** field,int width){
	srand(time(0));
	int pruning_state=1;
	int arrange_y;
	while(pruning_state){
		pruning_state=0;
		for(int y=3;y<width+1;y+=2){                
			for(int x=width-2;x>0;x-=2){
				arrange_y = 1 + (y+x-2)%(width-1);        
				if(field[arrange_y][x].path==0){
					field = void_plus(arrange_y,x,field,width);
					pruning_state++;
				}
			}  
		}  
	}  
	return field;
}

block** void_plus(int y,int x,block**field,int width){   //me.path==1, »óÅÂÇÑÅ× °ªÁÖ°í ±×³ð ÁÖº¯ Åë·Î °ª ÀçÁ¶Á¤
	int dice,surround=0;
	dice=(rand()%4);                    //printf("%d",dice);
	for(int z=0;z<4;z++){
		switch(dice){
			case 0:{    //up
				if(y!=1){      //printf("%d,%d/",a,b);            //printf("%d ",dice);
					if(field[y-2][x].path==1){      //printf("in to%d",dice);
						up.wall=0;
						me.path=1;
						void_chain(y,x,field);      //void_check(maze);      //wall_check(maze);
						return field;
					}
					if(up.wall==1){
						surround++;
					}
				}
				else{
					surround++;
				}
				dice++;
			}break;
			case 1:{  //right
				if(x!=(width-2)){        //printf("%d,%d/",a,b);      //printf("%d ",dice);
					if(field[y][x+2].path==1){    //printf("in to%d",dice);
						right.wall=0;
						me.path=1;
						void_chain(y,x,field);    //        void_check(maze);      //      wall_check(maze);
						return field;
					}
					if(right.wall==1){
						surround++;
					}
				}
				else{
					surround++;
				}
				dice+=2;
			}break;
			case 2:{  //down
				if(y!=(width-2)){      //    printf("%d,%d/",a,b);            //    printf("%d ",dice);
					if(field[y+2][x].path==1){      //      printf("in to%d",dice);
						down.wall=0;
						me.path=1;
						void_chain(y,x,field);      //      void_check(maze);      //      wall_check(maze);
						return field;
					}
					if(down.wall==1){
						surround++;
					}
				}
				else{
					surround++;
				}
				dice-=2;
			}break;
			case 3:{  //left
				if(x!=1){    //      printf("%d,%d/",a,b);    //      printf("%d ",dice);
					if(field[y][x-2].path==1){    //        printf("in to%d",dice);
						left.wall=0;
						me.path=1;
						void_chain(y,x,field);      //      void_check(maze);      //      wall_check(maze);
						return field;
					}
					if(left.wall==1){
						surround++;
					}
				}
				else{
					surround++;
				}
				dice--;
			}break;
		}
	}  //printf("\n");
	if(surround==4){
		int done=1;
		while(done){
			switch (dice) {
				case 0:{
					if(y!=1){
						up.wall=0;
						done--;
					}
					else{
						dice++;
					}
				}break;
				case 1:{
					if(x!=(width-2)){
						right.wall=0;
						done--;
					}
					else{
						dice+=2;
					}
				}break;
				case 2:{
					if(y!=(width-2)){
						down.wall=0;
						done--;
					}
					else{
						dice-=2;
					}
				}break;
				case 3:{
					if(x!=1){
						left.wall=0;
						done--;
					}
					else{
						dice--;
					}
				}break;
			}
		}
	}
	return field;
}

mazeframe::~mazeframe(){
	delete field;
}