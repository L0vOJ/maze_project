#include<iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
int main(){
	char* hello;
	printf("%s",hello);
	cout<<hello;
	int out = strcmp(hello,"hello")?1:0;
	cout<<out;
}