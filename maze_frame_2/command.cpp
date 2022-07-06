#include<iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "main_frame.h"
#include "getch.cpp"

using namespace std;

command::command(){
	keybind = new int[9];
	int arr[9] = {113,119,101,97,115,100,122,120,99};
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
	while(true){
		system("clear");
		cout<<"1.maze generate"<<endl<<"2.maze solve"<<endl<<"3.maze play"<<endl;
		this->navigate(keybinding(getch()));
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
			dm = new mazeframe;
			cout<<"press any key to exit"<<endl;
			getch();
		}break;
		case 2:{
			cout<<"this is 2"<<endl;
			cout<<"maze_check"<<endl;
			dm->checkfield();
			dm->get_width();
			cout<<"press any key to exit"<<endl;
			getch();
		}break;
		case 3:{
			cout<<"this is 3"<<endl;
			cout<<"maze_solve&_path_check"<<endl;
			dm->path_solve();
			dm->path_check();
			cout<<"press any key to exit"<<endl;
			getch();
		}break;
		case 4:{
			cout<<"this is 4"<<endl;
			cout<<"maze_timecheck"<<endl;
			dm->show_timelog();
			cout<<"press any key to exit"<<endl;
			getch();
		}break;
		case 5:{
			cout<<"this is 5"<<endl;
			cout<<"press any key to exit"<<endl;
			getch();
		}break;
		case 6:{
			cout<<"this is 6"<<endl;
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