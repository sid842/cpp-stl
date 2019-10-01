//Associative Containers
//Map Key to value
//map, multimap -> <map> header
//set, multiset -> <set> header
//later unordered version of each of the stl was implemented

#include <iostream>
#include <ostream>
#include <map>
#include <string>

using namespace std;

void foo(const map<int, string>& m) {
	//Below line doesn't work since operator[] tries to modify the map 
	//cout << m[3] << " ";
	map<int, string>::const_iterator itr = m.find(3);	//could have used auto here

	if(itr == m.end()) {
		cout << "not found" << endl;
	} else {
		cout << "found:" << itr->second << endl;
	}
}

int main() {

	map<int, string> m;

	m[1] = "one";
	m[2] = "two";
	m[3] = "three";
	m[4] = "four";
	m[2] = "TWO!";	//operator[] returns string& here since value exists

	//Each element of map is of type pair<const K, V>
	//here it is pair<const int, string>

	//map<int, string>::iterator, this is verbose
	// this loops is very similar to that used for vectors and other stls
	for (auto itr = m.cbegin(); itr != m.cend(); ++itr) { 
		//Since we are using map we get elements in the sorted order of keys
		//Default behaviour is less than '<'
		cout <<  "(" << itr->first << ", " << itr->second << ")" << endl;
	}

	foo(m);

	//map is implemented with a balanced binary tree
	//insert O(log N)
	//erase O(log N)

	m.clear();
}