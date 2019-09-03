#include <iostream>
using namespace std;
#include <string.h>
class person{
protected:
	char * name;
	char * lastname;
public:
	person(char * name, char * lastname){
		this->name = new char[strlen(name) + 1];
		this->lastname = new char[strlen(lastname) + 1];
		strncpy(this->name, name, strlen(name) + 1);
		strncpy(this->lastname, lastname, strlen(lastname) + 1); 
	}
	int myfunc(int,int);
};

class student : public person{
	int studentCode;
public:
	student(char * name, char * lastname):person(name, lastname){} //inheritance with constructor
	int myfunc(int a){ //function overwriting
		return person::myfunc(a,10); //call parent function
	}
};

class base{
public:
	int i;
};
class d1 : virtual public base{ //virtual class

};
class d2 : virtual public base{ //virtual class

};
class d3 : public d1, public d2 , virtual public base{ // multi inheritance

};
class d4: private base{
public:
	base::i; //granting access
};
int main(){
	d3 o;
	o.i = 2; //o.d1::base::i
	return 0;
}