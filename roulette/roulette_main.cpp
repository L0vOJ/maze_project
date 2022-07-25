#include"../lib/getch.cpp"
#include"main_frame.h"
#include"Casino.cpp"

using namespace std;

int input[5][5] = {{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}};

int main(){
	srand(time(0));
	Casino open;
	while(1){
		for(int z=0;z<5;z++){
			open.fund_roulette(input[z]);
			open.show_chart1();
			if(open.get_fund()<1){
				cout<<"game over! peak:"<<open.get_peak();
				open.__init__(200);
				break;
			}
		}
		getch();
		system("clear");
	}
}

