#include<iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <math.h>
#include "main_frame.h"
using namespace std;

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

void pathfinding::solution_check(){
  for(int y=0;y<width;y++){
    for(int x=0;x<width;x++){
      if(me.wall){
        printf("■ ");
      }
      else if(me.cline){
        printf("**");
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
}