#include <iostream>
using namespace std;
class Parent {
	protected :
    	int id;
    	int adder;
    public:
    	Parent(){
    		id=0;
    		adder=7;
    	}

};
class Child1 : public Parent {
public :
    void set_id(int i) {
        id = i;
    }
    void print_id() {
    	cout<<"ID:"<<id<<endl;
    }
    int add(){
    	return (id+adder);
    }
};
class Child2 : public Parent {
public :
    void set_id(int i) {
        id = i;
    }
    void print_id() {
    	cout<<"ID:"<<id<<endl;
    }
    int subtract(){
    	return (id-adder);
    }
};
int main(void)
{
    Child1 child1;
    Child2 child2;
    child1.set_id(10);
    child2.set_id(10);
    cout<<child1.add()<<endl;
    cout<<child2.subtract()<<endl;
    return 0;
}