#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

using namespace std;

int main() {
	const int arr[] = { 22, 99, 33, 44, 55};

	vector<int> v;
	v.push_back(11);
	v.push_back(77);

	for(auto itr = v.begin(); itr != v.end(); ++itr) {
		cout << *itr << " " ;
	}

	cout << endl;

	//copy to back inserter
	//If we need to append elements to the vector from an array, we can use this
	copy(arr, arr + sizeof(arr) / sizeof(arr[0]), back_inserter(v));

	//range insertion
	//v.insert(v.end(), firstItr, secondItr)

	for_each(v.begin(), v.end(), [](int n) { cout << n << " "; });
	cout << endl;
	//vector<T> v(firstItr, secondItr) is also another way to create a vector

	//sorting a vector
	sort(v.begin(), v.end());

	//another way to print contents on the console, not recommended
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//binary search
	auto itr = lower_bound(v.begin(), v.end(), 50);
	cout << itr - v.begin() << endl;

	//If vector doesn't contain the element to be searched, it returns the position
	//where the element could be inserted. 

	v.clear();


}