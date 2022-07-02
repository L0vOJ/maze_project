#include<iostream>
#include <cstdlib>
#include <string>
#include "maze_frame/main_frame.h"	//mazeframe here
#include "maze_frame/frame_init.cpp"
#include "maze_frame/maze_check.cpp"
#include "maze_frame/pathfinder.cpp"
using namespace std;

int main(int argc, char **argv){
	system("clear");
	mazeframe hello(argc,argv);
	hello.ckeckfield();
	pathfinding path(argc,argv);
	path.solution_check();
}