#include<iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <math.h>
#include "main_frame.h"	//mazeframe here
#include "frame_init.cpp"
#include "maze_check.cpp"
#include "maze_solver.cpp"
#include "maze_member.cpp"
using namespace std;

int main(int argc, char **argv){
	system("clear");
	mazeframe hello(argc,argv);
	hello.ckeckfield();
	hello.path_solve();
	hello.solution_check();
	hello.solve_clear();
	hello.solution_check();
	//maze_solver path(argc,argv);
	//path.ckeckfield();
	//path.solution_check();
	//cout<<path.get_escape_step();
}