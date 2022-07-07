#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(){
	std::vector<string*> v;
	string* what = new string("hell0\0yo\0nice\0to\0meet\0ou");
	v.push_back(what);
	cout<<*v.at(0);
}
