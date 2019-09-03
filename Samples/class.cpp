#include <iostream>
using namespace std;
class MyClass
{
	static int c;
public:
	int func1();
	int a;
	MyClass(int = 0, int = 0, int = 0);
	MyClass(const MyClass &);
	~MyClass();
	static int getcount();
	
};
int MyClass::func1(){
	return 2;
}
MyClass::MyClass(int a , int b , int c ){
	a = 0;
}
int main(){
	MyClass a(1,2,3); // MyClass *a = new MyClass(); , delete a;
	MyClass b[10] = {MyClass(), MyClass(1,1,1)};
	a.func1();
	return 0;
}