#include <iostream>
using namespace std;
double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
double & func(int & i){
	int b = i;
	return vals[i];
}
int main(){
	int a = 10;
	int & b = a; // alias, initialize immidietly
	func(a);
	func(a) = 10;
	return 0;
}