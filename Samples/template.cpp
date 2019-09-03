#include <iostream>
using namespace std;

template <class A>
A func1(A a, A b){
	A c = a + b;
	return c;
}

template <class A, class T>
void func2(A a, T b){
	T c = b;
	return;
}

template <class A, class T>
int func1(A a, T b, T c){ //function template overloading
	return 1;
}

template <class T>
class tclass{
	T a;
	T b;
	T c;
public:
	int func(T a);
};
template <class T>
int tclass<T>::func(T a){
	return 1;
}

template<> class tclass<int> { //class specialize
	int a;
	int b;
public:
	int show();
};

template <class T>
class A{ //template class composition
	tclass<T> z;
public:
	A(): z(){};
};

class B{ //template class composition
	tclass<int> z;
public:
	B(): z(){};
};
int func2(int,int); //specific type
int main(){
	int a = func1(1,2);
	func2<int,double>(1,1.1);
	tclass<int> c;
	return 0;
}