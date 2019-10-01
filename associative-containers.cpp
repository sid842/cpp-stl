//Associative Containers
//Map Key to value
//map, multimap -> <map> header
//set, multiset -> <set> header
//later unordered version of each of the stl was implemented

#include <iostream>
#include <ostream>
#include <map>
#include <unordered_map>
#include <string>
#include <functional>

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

	// map<int, string> m;
	map<int, string, greater<int>> m; //greater comparator defined in <functional>

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

	//map is implemented with a balanced binary tree
	//insert O(log N)
	//erase O(log N)
	//lookup O(log N)

	m.clear();

	//multimap associates single key with many values while map uses one to one mapping
	//multimap doesn't overload operator[]

	//set and multiset since templated on a single type, don't use operator[]
	//set is a sorted container that enforces uniqueness 
	//time complexities similar to map

	//unordered map has similar interface to map but the implementation is 
	//based on hash tables

	//insertion, deletion and lookup is amortized O(1)

	unordered_map<int, string> um;

	um[1] = "one";
	um[2] = "two";

	cout << um[2] << endl;

	um.clear();

	//map is a better choice since can also be modified with the help of comparator.
	//for map you only need a comparator while for unordered_map you need to define
	//a good hash function that doesn't lead to too many collisions. Also need an equality 
	//predicate so as to check whether two objects are equal or not.



}