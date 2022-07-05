#include <iostream>
using namespace std;
int main(){
	int msgs;//input 6bit
	cin>>msgs;
	msgs = msgs>63?63:msgs;
	int led[6]; //012345
	for(int zzz=0;zzz<6;zzz++){
		led[zzz] = (msgs&1<<(5-zzz))?1:0;
	}
	for(int zzz=0;zzz<6;zzz++){
		cout<<led[zzz];
	}
	cout<<endl;
}