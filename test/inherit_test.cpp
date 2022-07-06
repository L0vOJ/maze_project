#include <iostream>
using namespace std;

class A {
private:
	int a;
protected:
	int b;
public:
	int c;
};

class B : A { //b,c맴버 변수는 private 맴버로 접근 범위 졻혀짐

};


int main() {
	B b;
    //a = private, b = private, c = private
	b.a;
	b.b;
	b.c;
}