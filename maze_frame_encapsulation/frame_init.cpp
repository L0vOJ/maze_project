#include<iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <math.h>
#include "main_frame.h"

using namespace std;

#define up field[y-1][x]
#define down field[y+1][x]
#define left field[y][x-1]
#define right field[y][x+1]
#define me field[y][x]

#define ct_wall_width ((width-3)/2) 
#define ct_void_width ((width-1)/2) 

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
int* roll();
void change(int* arr);
int connection(int a,int b, int level,int direction,block**maze);


mazeframe::mazeframe(){
	width=5;
	width = width*4+1;
	mode = 1;
	field = field_make(field,width);
}

mazeframe::mazeframe(int argc,char** argv){
	width=5;
	width = width*4+1;
	mode = (argc>1)?(strcmp(argv[1],"-n")?1:0):1;
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
			y=2*(1+rand()%(ct_wall_width));  
		}
		else{
			y=1+2*(rand()%(ct_void_width)); 
		}
		if(me.wall==0){ 
			tap++;
		}
		me.wall=1;
		if(tap>=(pow(width,2)-pow(ct_void_width,2)-pow(ct_wall_width,2))/3){
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
		for(int y=2;y<width-2;y+=2){              
			for(int x=2;x<width-2;x+=2){
				arrange_y = 2 + (y+x-4)%(width-3);     
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
  int trial,surround=0;
  int* direction;
  direction=roll();
  for(int z=0;z<4;z++){
    trial=connection(y,x,1,direction[z],field);
    if(trial==-1){
      free(direction);
      return field;
    }
    else{
      surround=trial;
    }
  }
  if(surround==0){
    switch (direction[3]) {
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
  free(direction);
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
  int trial,surround=0;
  int* direction;
  direction=roll();
  for(int z=0;z<4;z++){
    if(direction[z]==0 && y==1){             //ÇØ´ç ¹æÇâÀ¸·Î ³ª¾Æ°¥ ¼ö ¾øÀ½-->±×·¡¼­ µÑ·¯½ÎÀÎ ¿Üº®ÀÇ °³¼ö ¿©ºÎ¸¦ Á¶»ç
      surround++;                         //+¹è¿­ À½¼ö°ª ÀÎµ¦½º Á¢±Ù ¹æÁö
      continue;
    }
    if(direction[z]==1 && x==(width-2)){
      surround++;
      continue;
    }
    if(direction[z]==2 && y==(width-2)){
      surround++;
      continue;
    }
    if(direction[z]==3 && x==1){
      surround++;
      continue;
    }
    trial=connection(y,x,0,direction[z],field);   //ÇØ´ç ¹æÇâÀÌ ¿ÜºÎ¿¡ °É¸®Áö ¾Ê¾Æ Á¢±ÙÀÌ °¡´ÉÇÏ´Ù¸é connection È£Ãâ
    if(trial==-1){                            //¿¬°á ÀÛ¾÷ ¼º°øÀû->ÇÔ¼ö Á¾°á
      free(direction);
      return field;
    }
    else{                                   //¾Æ´Ï¶ó¸é
      surround=trial;                         //µÑ·¯½ÎÀÎ º® °ª °»½Å ÈÄ ´ÙÀ½ direction¿¡ ´ëÇØ ´Ù½Ã ¼öÇà
    }
  }  //printf("\n");
  if(surround==4){        //¹Ì·Î Å©±â°¡ ¾öÃ» Å¬¶§´Â È¿°ú¸¦ ÁÙ ¼öµµ ÀÖ°ÚÁö¸¸ Å©Å° 200 ÀÌ³»¿¡¼­´Â °ÅÀÇ ¾²ÀÌÁö ¾Ê´Â °Í °°´Ù.
    int done=1;
    while(done){
      switch (direction[3]) {
        case 0:{
          if(y!=1){
            up.wall=0;
            done--;
          }
          else{
            direction[3]++;
          }
        }break;
        case 1:{
          if(x!=(width-2)){
            right.wall=0;
            done--;
          }
          else{
            direction[3]+=2;
          }
        }break;
        case 2:{
          if(y!=(width-2)){
            down.wall=0;
            done--;
          }
          else{
            direction[3]-=2;
          }
        }break;
        case 3:{
          if(x!=1){
            left.wall=0;
            done--;
          }
          else{
            direction[3]--;
          }
        }break;
      }
    }
  }
  free(direction);
  return field;
}

int connection(int y,int x, int level,int direction,block**field){
  int next[2][4];
  if(direction==0){ //º£¿­ À½¼ö °Çµé¸é ÅÍÁü ¸ø°Çµé°Ô ifÀý·Î ¸·¾ÆµÒ
    next[0][0]=field[y-2][x].path;
    next[1][0]=field[y-2][x].root;
  }
  else if(direction==1){
    next[0][1]=field[y][x+2].path;
    next[1][1]=field[y][x+2].root;
  }
  else if(direction==2){
    next[0][2]=field[y+2][x].path;
    next[1][2]=field[y+2][x].root;
  }
  else if(direction==3){
    next[0][3]=field[y][x-2].path;
    next[1][3]=field[y][x-2].root;
  }
  if(next[level][direction]==1){  //ÇØ´ç ¹æÇâÀ¸·Î ³ª¾Æ°¡¾ß ÇÑ´Ù¸é level==0 --> ÇØ´ç ¹æÇâÀ¸·Î º» Åë·Î°¡ ¶Õ·Á ÀÖ´Ù¸é leve==1 --> ÇØ´ç ¹æÇâÀ¸·Î ¿Ü°¢°ú ÀÌ¾îÁø »Ñ¸®°¡ ÀÖ´Ù¸é
    switch (direction) {          // level==0 º®À» Çã¹°°Å³ª  level==1 º®À» ÀÕ°Å³ª
      case 0:{
        up.wall=level;
      }break;
      case 1:{
        right.wall=level;
      }break;
      case 2:{
        down.wall=level;
      }break;
      case 3:{
        left.wall=level;
      }break;
    }
    if(level){                   //¿¬¼â ÀÛ¾÷ ¼öÇà
      me.root=1;
      root_chain(y,x,field);
    }
    else{
      me.path=1;
      void_chain(y,x,field);
    }
    return -1;                  //¿¬¼â ÀÛ¾÷ ¿Ï·á
  }
  int wall_dr[4];               //¿¬¼â ÀÛ¾÷ ¼öÇà ÄÉÀÌ½º°¡ ¾Æ´Ï¶ó¸é (ÁÖº¯ Áß¿ä ¿¬°á °í¸®¿¡ Á÷Á¢ ¿¬°áµÇÁö ¸øÇß´Ù¸é)
  wall_dr[0]=up.wall;
  wall_dr[1]=right.wall;
  wall_dr[2]=down.wall;
  wall_dr[3]=left.wall;
  int surround=0;
  if(wall_dr[direction]==1){
    surround++;
  }
  return surround;          //ÇØ´ç ¹æÇâÀ¸·Î µÑ·¯½ÎÀÎ ³»º®ÀÇ °³¼ö¸¦ ¹ÝÈ¯ --> ÀÌ¸¦ ÅëÇØ À­´Ü°èÀÇ ÇÔ¼ö°¡ ·£´ý ¿¬°á ÀÛ¾÷À» ¼öÇàÇÒÁö °áÁ¤ÇÔ
}

int* roll(){
  int* arr;
  arr=new int[4];
  for(int a=0;a<4;a++){
    arr[a]=a;
  }
  for(int a=0;a<12;a++){
    change(arr);
  }
  return arr;
}

void change(int* arr){
  int buffer;
  int choice[2];
  for(int a=0;a<2;a++){
    choice[a]=rand()%4;    //rand ÃÖ´ë°ª: size-1; ¹è¿­ °¡Àå Å« ÀÎµ¦½º³Ñ¹ö¿Í °°´Ù
  }
  buffer = arr[choice[0]];
  arr[choice[0]] = arr[choice[1]];
  arr[choice[1]] = buffer; //±³È¯ ¿Ï·á
}

mazeframe::~mazeframe(){
	delete field;
}