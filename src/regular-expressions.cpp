//regex - Flexible String Processing
//This we can do with regex:
//->Validation - input is well formed
//->Decision - what set does this string belong to
//->Parsing - is input date
//->Transformation - escape characters
//->Iteration - find occurrence of pattern within a string
//->Tokenization - Systematically split apart a string

#include <ios>
#include <iostream>
#include <ostream>
#include <regex>
#include <string>

using namespace std;

int main () {

/*
*When the boolalpha format flag is set, bool values are inserted/extracted 
*by their textual representation: either true or false, instead of integral values.
*
*This flag can be unset with the noboolalpha manipulator.
*/
	cout << boolalpha;

	const regex r("ab+c");

	for(string s; getline(cin, s); ) {
		cout << regex_match(s, r) << endl;
		cout << endl;
	}

	/**
		regex_match()
		regex_search()
		regex_replace()
	*/
}