//Use smart pointers instead of new and delete
//shared_ptr and unique_ptr, live in <memory>
//don't use auto_ptr, unqiue_ptr has replacced it completely

#include <memory>
#include <iostream>
#include <ostream>
#include <utility>

using namespace std;

int main() {
	unique_ptr<int> up(new int(1729));
	//when up goes out of scope, it automatically deletes the pointer

	cout << *up << endl;

	//unique ptrs cannot be copied but moved
	unique_ptr<int> up2 = move(up);
	//up now becomes nullptr

	//if you use move for vectors, list, they might be in an undefined state so don't use 
	//them after moving them.

	if (up) {
		cout << "uh oh" << endl;
	} else {
		cout << "yay" << endl;
	}

	cout << *up2 << endl;

	cout << "Shared pointers" << endl;

	//shared_pointers are able to share ownership by reference counting
	shared_ptr<int> sp = make_shared<int>(1234); //can used auto here
	shared_ptr<int> sp2(sp);

	cout << *sp << endl; 
	cout << *sp2 << endl;

	//point to note: don't use shared_ptr<X[]>, since in its destructor delete gets called
	
}