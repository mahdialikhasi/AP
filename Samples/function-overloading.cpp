#include <iostream>
using namespace std;
int func(int a){
	return 1;
}
int func(double a = 10){
	return 1;
}
void func(double a, int b){
	return;
}
int main(){
	return 0;
}