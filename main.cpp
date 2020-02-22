// main.cpp

#include "Quash.h"
#include <sstream>  // for stringstream
#include <iostream>  // for cout
using namespace std;

int main(int argc, char *argv[]) {  // argc = # inputs, argv = array of cstrings

	if (argc!=2) { cerr << "no input\n"; return 1; }

	stringstream ss(argv[1]);
	string word="";
	int num=0;
	char comma;

	Quash q;
	int count=0;
	string message="";

	while (ss >> word) {
		if (word=="deleteMin" || word=="deleteMin,") {
			pair<int,int> p = q.deleteMin();
			if (p.second==-1) message="min item not present since table is empty";
			else if (p.second==0) message="min item successfully deleted";
			else message="min item = " + to_string(p.first) + ", count decremented, new count = " + to_string(p.second);
			cout << message << endl;
			continue;
		}
		if (word=="print," || word=="print") { q.print(); continue; }

		ss >> num;
		if (word=="insert") {
			count = q.insert(num);
			if (count==1) message="item successfully inserted, count = " + to_string(count);
			else if (count==0) message="not inserted, debug that SHIT BRO, DAMN";
			else message="item already present, new count = " + to_string(count);
			cout << message << endl;
		} 
		else if (word=="lookup") {
			count = q.lookup(num);
			if (count==0) message="item not found";
			else message="item found, count = " + to_string(count);
			cout << message << endl;
		} 
		else if (word=="delete") {
			count = q.deleteItem(num);
			if (count==-1) message="item not present in the table";
			else if (count==0) message="item successfully deleted";
			else message="item count decremented, new count = " + to_string(count);
			cout << message << endl;
		}
		ss >> comma;  // extract the comma after each command, to allow ss to move onto next command
	}
			



	return 0;
}
