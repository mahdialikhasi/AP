#include <iostream>
using namespace std;
#include <fstream>
#include <set>
#include <string>
int main(){
	/*Opening file*/
	ifstream infile;
	infile.open("myfile.txt");
	if(infile.is_open() == false)
		return -1;
	/*keywords:: using set becuase the keywords are unique and we can search in theme using set*/
	set<string> keywords;
	/*reading keywords*/

	//int begining = infile.tellg();
	//infile.seekg(0, ios::end);

	//int size = infile.tellg();
	//infile.seekg(0, begining);

	while(infile.eof() == false){
		string tmp;
		infile >> tmp;
		keywords.insert(tmp); //add keyword to set
		cout << tmp;
		char c;
		infile >> c;

		if(c == '\n') //end of line
			break;
	}
	set<string>::iterator keyIterator = keywords.find("citycenter");
	cout << *keyIterator;
	return 0;
}
