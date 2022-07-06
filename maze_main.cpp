#include<iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <math.h>
#include "maze_frame_inherit/main_frame.h"	//mazeframe here
#include "maze_frame_inherit/frame_init.cpp"
#include "maze_frame_inherit/maze_check.cpp"
#include "maze_frame_inherit/maze_solver.cpp"
using namespace std;

int main(int argc, char **argv){
	system("clear");
	mazeframe hello(argc,argv);
	hello.ckeckfield();

	//maze_solver path(argc,argv);
	//path.ckeckfield();
	//path.solution_check();
	//cout<<path.get_escape_step();
}