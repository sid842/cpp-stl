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

int main() {

	map<int, string> m;

	m[1] = "one";
	m[2] = "two";
	m[3] = "three";
	m[4] = "four";

	cout << m[2] << endl;

	m.clear();
}