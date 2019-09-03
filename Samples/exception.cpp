#include <iostream>
using namespace std;

int main(){
	try{
		throw 100;
	}catch(int a){

	}catch(double b){

	}catch(type1 c){
		throw; //rethrow
	}
	return 0;
}