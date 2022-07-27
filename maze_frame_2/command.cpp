#include<iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <functional>
#include <vector>
#include <math.h>
#include "main_frame.h"
#include "getch.cpp"

using namespace std;

command::command(){
	keybind = new char[9];
	char arr[10] = {"qweasdzxc"};
	for(int zz=0;zz<9;zz++){
		keybind[zz] = arr[zz];
	}
}

int command::keybinding(char key){	//qweasdzxc를 1~9로 바꾼다	//이거 설정 변경 멤버는 추후 만들어야함
	for(int zz=0;zz<9;zz++){
		if(key==keybind[zz]) {
			return zz+1;
		}
	}
	return 0;
}

void command::run(){
	long long cursor = 1;
	cout<<"---hello---"<<endl;
	while(true){
		//cout<<"1.maze generate"<<endl<<"2.maze solve"<<endl<<"3.maze play"<<endl;
		system("clear");
		cout<<cursor<<endl;
		cursor = this->presskey_to_change(cursor,0);
		//cursor = this->navigate(cursor);
	}
}

long long command::navigate(long long input){
	cout<<"this is"<<input<<endl;
	switch(input){
		case 11:
		break;
		case 41:
		break;
		case 51:
		break;
		case 211:
		break;
		case 221:
		break;
		case 231:
		break;
		case 241:
		break;
		case 311:
		break;
		case 321:
		break;
		case 331:
		break;
		case 341:
		break;
		default: 
			//return menu(input);
		break;
	}
	cout<<"press any key to exit"<<endl;
	return input/_maxListSize;
}

/*
long long command::menu(long long input){
	switch(input/10){
		case 0:
			input = menulist(input);
		break;
		case 2:
		break;
		case 3:
		break;
		default: 
		break;
	}
}
long long command::menulist(long long input){
	
}
*/
/*
void command::log_show(){
	for(int zz=0;zz<dm.size();zz++){
		printf("%3d.",zz+1);
		dm.at(zz)->show_timelog();
	}
}

int command::log_browse(){
	int cursor = 0;
	while(true){
		system("clear");
		for(int zz=0;zz<dm.size();zz++){
			if(cursor==zz) cout<<"*";
			printf("\t%d.",zz+1);
			dm.at(zz)->show_timelog();
		}
		switch(keybinding(getch())){
			case 2:{
				cursor = cursor?cursor-1:0;
			}break;
			case 5:{
				cursor = (cursor<dm.size()-1)?cursor+1:cursor;
			}break;
			case 6:{
				system("clear");
				dm.at(cursor)->checkfield();
				return 0;
			}break;
		}
	}
}
*/
long long command::presskey_to_change(long long input,int forbidden){	//maxListSize 활용해 정한다
	int decision = keybinding(getch());
	if(decision==forbidden) return input;
	else{
		switch(decision){
			case 2:{
				input = ((input-1)%_maxListSize)?input-1:input;
			}break;
			case 4:{
				input = (input/_maxListSize)?input/_maxListSize:input;
			}break;
			case 5:{
				input = ((input+1)%_maxListSize)?input+1:input;
			}break;
			case 6:{
				input = (input<=Maxval)?input*_maxListSize+1:input;
			}break;
		}
	}
	return input;
}