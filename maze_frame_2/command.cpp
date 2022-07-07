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
	while(true){
		system("clear");
		//cout<<"1.maze generate"<<endl<<"2.maze solve"<<endl<<"3.maze play"<<endl;
		cursor = presskey_to_change(cursor);
		cout<<cursor;
		//this->navigate(cursor);
	}
}

void command::navigate(int input){
	switch(input){
		case 0:{			
			cout<<"this is 0"<<endl;
			cout<<"error"<<endl;
			cout<<"press any key to exit"<<endl;
			getch();
		}break;
		case 1:{
			cout<<"this is 1"<<endl;
			cout<<"maze_generate"<<endl;
			mazeframe* m_new = new mazeframe;
			if(dm.size()>=maxListSize) dm.erase(dm.begin());
			dm.push_back(m_new);
			cout<<"press any key to exit"<<endl;
			getch();
		}break;
		case 2:{
			cout<<"this is 2"<<endl;
			cout<<"maze_check"<<endl;
			dm.at(dm.size()-1)->checkfield();
			cout<<"press any key to exit"<<endl;
			getch();
		}break;
		case 3:{
			cout<<"this is 3"<<endl;
			cout<<"maze_solve&_path_check"<<endl;
			dm.at(dm.size()-1)->path_solve();
			dm.at(dm.size()-1)->path_check();
			cout<<"press any key to exit"<<endl;
			getch();
		}break;
		case 4:{
			cout<<"this is 4"<<endl;
			cout<<"maze_timecheck"<<endl;
			dm.at(dm.size()-1)->show_timelog();
			cout<<"press any key to exit"<<endl;
			getch();
		}break;
		case 5:{
			cout<<"this is 5"<<endl;
			cout<<"maze_logfile_browse"<<endl;
			this->log_show();
			cout<<"press any key to exit"<<endl;
			getch();
		}break;
		case 6:{
			cout<<"this is 6"<<endl;
			this->log_browse();
			cout<<"press any key to exit"<<endl;
			getch();
		}break;
		case 7:{
			cout<<"this is 7"<<endl;
			cout<<"press any key to exit"<<endl;
			getch();
		}break;
		case 8:{
			cout<<"this is 8"<<endl;
			cout<<"press any key to exit"<<endl;
			getch();
		}break;
		case 9:{
			cout<<"this is 9"<<endl;
			cout<<"press any key to exit"<<endl;
			getch();
		}break;
		case 10:{
			cout<<"this is 10"<<endl;
			cout<<"press any key to exit"<<endl;
			getch();
		}break;
		case 11:{
			cout<<"this is 11"<<endl;
			cout<<"press any key to exit"<<endl;
			getch();
		}break;
		default: break;
	}
}


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

long long command::presskey_to_change(long long input){	//maxListSize 활용해 정한다
	switch(keybinding(getch())){
		case 2:{
			input = ((input-1)%maxListSize)?input-1:input;
		}break;
		case 4:{
			input = (input/maxListSize)?input/maxListSize:input;
		}break;
		case 5:{
			input = ((input+1)%maxListSize)?input+1:input;
		}break;
		case 6:{
			input = (input<=Maxval)?input*maxListSize+1:input;
		}break;
	}
	return input;
}