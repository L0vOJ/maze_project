#include"main_frame.h"

using namespace std;

#define INIT_FUND 100

Casino::Casino():__fund(INIT_FUND),__count(0),__peak(0){
    sheetConfig1();
    chartConfig1();
}

Casino::Casino(int fund):__fund(fund),__count(0),__peak(0){
    sheetConfig1();
    chartConfig1();
}

void Casino::__init__(int fund=100){
    __fund=fund;
    __count=0;
    __peak=0;
    for(int z=0;z<__sheet1.div;z++){
        __chart1.count[z]=0;
        __chart1.earn[z]=0;
    }
}

void Casino::sheetConfig1(){
    __sheet1.div = 5;
    __sheet1.probList = new int[__sheet1.div]{12,6,4,2,1};
    __sheet1.mag = new int[__sheet1.div]{2,3,5,10,20};
    __sheet1.totalProb=0;
    for(int z=0;z<__sheet1.div;z++){
        __sheet1.totalProb+=__sheet1.probList[z];
    }
}

void Casino::chartConfig1(){
    __chart1.count = new int[__sheet1.div]{0,0,0,0,0};
    __chart1.earn = new int[__sheet1.div]{0,0,0,0,0};
}

int Casino::get_fund(){
    return __fund;
}

int Casino::get_peak(){
    return __peak;
}

void Casino::show_chart1(){
    cout<<"---------------------------------------------------------------"<<endl;
    for(int y=0;y<3;y++){
        cout<<"  |";
        for(int z=0;z<__sheet1.div;z++){
           switch(y){
                case 0:
                    cout<<__sheet1.mag[z];
                break;
                case 1:
                    cout<<__chart1.count[z];
                break;
                case 2:
                    cout<<__chart1.earn[z];
                break;
           }
           cout<<"\t|  ";
        }
        switch(y){
            case 0:
                cout<<__peak<<"\t|  peak";
            break;
            case 1:
                cout<<__count<<"\t|  count";
            break;
            case 2:
                cout<<__fund<<"\t|  fund";
            break;
        }
        cout<<endl;
    }
}

int Casino::result_roulette(int* input){
	int roll = rand()%__sheet1.totalProb;
    int sum = 0;
	for(int z=0;z<__sheet1.div;z++){
        sum+=__sheet1.probList[z];
		if(roll<sum){
			return input[z]*__sheet1.mag[z];
		}
	} 
    return 0;
}

void Casino::fund_roulette(int* input){
	int roll = rand()%__sheet1.totalProb;
    __count++;
    int sum = 0;
    bool flag = true;
	for(int z=0;z<__sheet1.div;z++){
        __fund-=input[z];
        sum+=__sheet1.probList[z];
		if(roll<sum && flag){
            int result=input[z]*__sheet1.mag[z];
            __chart1.count[z]++;
            __chart1.earn[z]+=result;
            __fund+=result;
            __peak = (__fund>__peak)?__fund:__peak;
            flag = false;
		}
	} 
}
