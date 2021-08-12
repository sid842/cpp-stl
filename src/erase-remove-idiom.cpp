#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	vector<int> v = {11, 22, 33, 44, 55};

	//removing elements from vector

	//bad strategy - loop over elements and remove those which satisfy the condition
	//this is bad because it is O(n^2)

	//good strategy - use std::remove() and vector.erase() algorithm which works
	//by doing a linear scan and copying the elements to the front of the list and then
	//resizing the vector.
	//erase-remove idiom

	for(auto itr = v.begin(); itr != v.end(); itr++)
		cout << *itr << " ";

	cout << endl;

	//remove_if returns the itr to the end of the valid array after elements removed. 

	v.erase(remove_if(v.begin(), v.end(), [] (int e)
	{
		return e%2 == 1;
	}), v.end());

	for(auto itr = v.begin(); itr != v.end(); itr++)
		cout << *itr << " ";

	cout << "\n";

}