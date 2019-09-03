#include <iostream>
using namespace std;
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <string.h>
#include <list>
class hdata{
	int key;
	int data;
public:
	hdata(int key, int data){
		this->key = key;
		this->data = data;
	}
	bool operator<(const hdata& a){
		return this->data < a.data;
	}
	bool operator>(const hdata& a){
		return this->data > a.data;
	}
	int show(){
		return key;
	}
};
int main(){
	/*Opening file*/
	ifstream infile;
	infile.open("myfile.txt");
	if(infile.is_open() == false)
		return -1;
	/*keywords:: using set becuase the keywords are unique and we can search in theme using set*/
	set<string> keywords;
	/*reading keywords*/

	/*int begining = infile.tellg();
	infile.seekg(0, ios::end);

	int size = infile.tellg();
	infile.seekg(0, ios::beg);

	infile.seekg(0, ios::beg);
	*/
	char data[10000];
	infile.getline(data, 10000);
	int size = infile.tellg();

	infile.seekg(0, ios::beg);
	while(infile.eof() == false){
		string tmp;

		infile >> tmp;

		keywords.insert(tmp); //add keyword to set

		//cout << tmp << infile.tellg() << endl;
		if(infile.eof() == true)
			break;
		//cout << "        " << infile.tellg() << "      " << size << endl;
		if(infile.tellg() >= (size - 1))
			break;
	}
	//set<string>::iterator keyIterator = keywords.find("citycenter");
	//cout << *keyIterator;

	int number;

	infile >> number;

	map<int,int> hotels; //create a map with hotelID as key and hotel rank as value
	for(int i = 0; i < number; i++){
		int hotelNumber;
		infile >> hotelNumber;
		//cout << hotelNumber;
		//infile >> hotelNumber;
		//cout << hotelNumber << "xx" << endl;
		//int curr = infile.tellg();
		//char c;
		//infile >> c;
		//cout << c;
		
		//cout << data;
		//infile.getline(data, 1000);
		ofstream newfile;
		newfile.open("newfile.txt");
		//newfile << hotelNumber << '\n';
		infile.getline(data, 10000);
		newfile << data;
		infile.getline(data, 10000);
		newfile << data;
		newfile.close();
		int val = 0;
		ifstream infile2;
		infile2.open("newfile.txt");
		
		while(infile2.eof() == false){
			string tmp;

			infile2 >> tmp;
			//cout << tmp;

			set<string>::iterator p = keywords.find(tmp);
			if(p != keywords.end()){
				val++;
			}
			//cout << size << "   " << infile.tellg();
			if(infile2.eof() == true){

				break;
			}
		}
		infile2.close();
		map<int,int>::iterator addVal = hotels.find(hotelNumber);

		if(addVal != hotels.end()) // hotel already exist
		{
			addVal->second += val;
		}else{
			hotels.insert(pair<int, int>(hotelNumber,val));
		}
	}
	map<int,int>::iterator hotelsIter = hotels.begin();
	list<hdata> hotelList; //for sorting
	for(;hotelsIter != hotels.end();hotelsIter++){
		hotelList.push_back(hdata(hotelsIter->first,hotelsIter->second));
	}
	hotelList.sort();
	hotelList.reverse();
	for(list<hdata>::iterator p = hotelList.begin(); p != hotelList.end(); p++){
		cout << p->show() << ',';
	}
	infile.close();
	return 0;
}
//Note :: I used this way becuase I dont have any resource for string :)
//there is lot of comment becuase I dont have debugger :)
//There is lot of mess becuase I dont have IDE :)