#include <iostream>
using namespace std;
#include <fstream>


int main(){
	ofstream outfile;
	outfile.open("myfile.txt");
	char data[100];
	if(outfile.is_open()){
		
		cin.getline(data, 100);
		outfile << data << endl;
		outfile.close();	
	}
	


	ifstream infile;
	infile.open("myfile.txt");
	infile >> data;
	cout << "Your data::" << data << endl;
	return 0;
}


	fstream b;
	b.open("test-open.txt", ios::in | ios::out | ios::ate);
	b.seekg(0, ios::beg);