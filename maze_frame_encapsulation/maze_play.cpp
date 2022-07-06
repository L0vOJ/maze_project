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
//-----------------------생성----------------
play_maze::play_maze(){
	mazeframe hello;
	maze = &hello;
}

play_maze::play_maze(int argc, char** argv){
	mazeframe hello(argc,argv);
	maze = &hello;
}

play_maze::play_maze(mazeframe& classA){
	maze = &classA;
}

//**snake아님 ! 미로
void play_maze::game_init(){
	this->field = maze->get_block();
	field[1][1].path = 1;
}

void play_maze::step(int decision){
	switch(decision){
		case 0:{

		}break;
		case 1:{

		}break;
		case 2:{

		}break;
		case 3:{

		}break;
		case 4:{

		}break;
		case 5:{

		}break;
		case 6:{

		}break;
		case 7:{

		}break;
		case 8:{

		}break;
		case 9:{

		}break;
	}
}

//-----------------------------------------
void play_maze::origin_check(){
	maze->checkfield();
}

play_maze::~play_maze(){}
