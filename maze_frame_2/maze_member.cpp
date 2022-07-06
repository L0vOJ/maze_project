#include<iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <math.h>
#include <ctime> //C++
#include "main_frame.h"

using namespace std;

#define up field[y-1][x]
#define down field[y+1][x]
#define left field[y][x-1]
#define right field[y][x+1]
#define me field[y][x]

#define ct_wall_width ((width-3)/2) 
#define ct_void_width ((width-1)/2) 

void mazeframe::set_block(block** field){
  this->field = field;
}
block** mazeframe::get_block(){
  return field;
}

int mazeframe::get_width(){
  return width;
}

void mazeframe::show_timelog(){
  cout<<t.year<<"-";
  cout<<(t.month+1)<<"-";
  cout<<t.day<<" ";
  cout<<t.hour<<":";
  cout<<t.min<<":";
  cout<<t.sec<<endl;
  //cout<<t<<endl;
}

void mazeframe::field_clear(){
  free(field);
}

void mazeframe::solve_clear(){
  this->root_clear();
  this->path_clear();
  this->cline_clear();
  escape_step = 0;
}

void mazeframe::wall_clear(){
  for(int y=1;y<width-1;y++){
    for(int x=1;x<width-1;x++){
     me.wall=0;
    }
  } 
}

void mazeframe::root_clear(){
  for(int y=0;y<width;y++){
    for(int x=0;x<width;x++){
      me.root=0;
    }
  } 
}

void mazeframe::path_clear(){
  for(int y=0;y<width;y++){
    for(int x=0;x<width;x++){
      me.path=0;
    }
  } 
}

void mazeframe::cline_clear(){
  for(int y=0;y<width;y++){
    for(int x=0;x<width;x++){
     me.cline=0;
    }
  } 
}

void mazeframe::regen(){
  this->field_clear();
  field = field_make(field,width);
}