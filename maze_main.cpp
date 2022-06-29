#include<iostream>
#include <cstdlib>
#include <string>
#include "mazeframe.h"	//mazeframe here
#include "mazeframe.cpp"

using namespace std;

int main(int argc, char **argv){
	//cout<<argc;
	if(argc>1){
		mazeframe hello(argv);
		hello.ckeckfield();
	}
	else{
		mazeframe hello;
		hello.ckeckfield();
	}
}