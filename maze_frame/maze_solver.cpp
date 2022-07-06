#include<iostream>
#include "main_frame.h"
using namespace std;

#define up field[y-1][x]
#define down field[y+1][x]
#define left field[y][x-1]
#define right field[y][x+1]
#define me field[y][x]

#define ct_wall_width ((width-3)/2) 
#define ct_void_width ((width-1)/2) 

block** path_search(int y,int x,block**field);
block** path_find(int y,int x,block**field);

void mazeframe::path_solve(){
  this->solve_clear();
  field[1][1].path=1;
  field = path_search(1,1,field);//path_check(field);
  field[width-2][width-2].cline=1;//width-2¼­ºÎÅÍ ½ÃÀÛ
  field = path_find(width-2,width-2,field);
  escape_step = field[width-2][width-2].path;
}

block** path_search(int y,int x,block**field){//new!!
  if(up.wall==0){
    if(field[y-2][x].path==0){
      field[y-2][x].path+=me.path+1;
      field = path_search(y-2,x,field);
    }
  }
  if(right.wall==0){
    if(field[y][x+2].path==0){
      field[y][x+2].path+=me.path+1;
      field = path_search(y,x+2,field);
    }
  }
  if(down.wall==0){
    if(field[y+2][x].path==0){
      field[y+2][x].path+=me.path+1;
      field = path_search(y+2,x,field);
    }
  }
  if(left.wall==0){
    if(field[y][x-2].path==0){
      field[y][x-2].path+=me.path+1;
      field = path_search(y,x-2,field);
    }
  }
  return field;
}

block** path_find(int y,int x,block**field){
  if(up.wall==0){
    if(me.path-field[y-2][x].path==1){//      printf("%d",me.path);
      up.cline=1;
      field[y-2][x].cline=1;//      printf("/%d/",field[y-2][x].cline);
      field = path_find(y-2,x,field);
    }
  }
  if(right.wall==0){
    if(me.path-field[y][x+2].path == 1){//      printf("%d",me.path);
      right.cline=1;
      field[y][x+2].cline=1;//      printf("/%d/",field[y][x+2].cline);
      field = path_find(y,x+2,field);
    }
  }
  if(down.wall==0){
    if(me.path-field[y+2][x].path== 1){//      printf("%d",me.path);
      down.cline=1;
      field[y+2][x].cline=1;//      printf("/%d/",field[y+2][x].cline);
      field = path_find(y+2,x,field);
    }
  }
  if(left.wall==0){
    if(me.path-field[y][x-2].path== 1){//      printf("%d",me.path);
      left.cline=1;
      field[y][x-2].cline=1;//      printf("/%d/",field[y][x-2].cline);
      field = path_find(y,x-2,field);
    }
  }
  return field;
}