#include<iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <math.h>

#include "main_frame.h"	//mazeframe here
#include "frame_init.cpp"
#include "maze_solver.cpp"
#include "maze_member.cpp"
#include "maze_check.cpp"
#include "maze_play.cpp"
#include "command.cpp"

using namespace std;

int main(int argc, char **argv){
	system("clear");
	srand(time(0));
	command lumos;
	lumos.run();
}