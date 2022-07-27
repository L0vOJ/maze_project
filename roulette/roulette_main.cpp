//#include"../lib/getch.cpp"
#include"main_frame.h"
#include"Casino.cpp"
#include"slot.cpp"

using namespace std;

int input[5][5] = {{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}};

void launch1(Casino open){
	while(1){
		for(int z=0;z<5;z++){
			open.fund_roulette(input[z]);
			open.show_chart1();
			if(open.get_fund()<1){
				cout<<"game over! peak:"<<open.get_peak();
				open.__init__();
				break;
			}
		}
		getch();
		system("clear");
	}
}

void launch2(Casino open){
	int cursor=0;
	int* input = new int[5]{0,0,0,0,0};
	while(1){
		//sleep(1);
		cursor = modify_slot(input,cursor);
		if(cursor==5 || cursor==-1){
			open.fund_roulette(input);
			cout<<"--->>"<<open.get_fund()<<endl;
			cursor=0;
			for(int z=0;z<5;z++) input[z]=0;
		}
		else{
			system("clear");
			for(int z=0;z<5;z++){
				cout<<"  |\t"<<open.get_sheet1_mag()[z];
			}
			cout<<"  |  fund"<<endl;
			for(int z=0;z<5;z++){
				cout<<"  |\t"<<input[z];
			}
			cout<<"  |\t"<<open.get_fund()<<endl<<"";
			for(int z=0;z<5;z++){
				if(z==cursor) cout<<"    -------";
				else cout<<"\t";
			}
		}
		//getch();

		
	}
}

int main(){
	srand(time(0));
	Casino open;
	//launch1(open);
	launch2(open);
}



