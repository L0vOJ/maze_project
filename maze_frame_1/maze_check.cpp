#include<iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <math.h>
#include "main_frame.h"
using namespace std;

void mazeframe::checkfield(){
	string wallicon;
	for(int y=0;y<width;y++){
		for(int x=0;x<width;x++){
			wallicon = mode?(me.wall?"■  ":"   "):(me.wall?"■ ":"  ");
			cout<<wallicon;
		}
		cout<<endl;
	}
}

void mazeframe::path_check(){
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

void mazeframe::path_check_num(){
  for(int y=0;y<width;y++){
    for(int x=0;x<width;x++){
      if(me.wall){
        printf("■ ");
      }
      else if(me.cline&&y%2&&x%2){
        cout<<me.path%100;
        if(me.path<10) cout<<" ";
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
}


/*
int mazeframe::get_escape_step(){
	return mazeframe;
}
*/