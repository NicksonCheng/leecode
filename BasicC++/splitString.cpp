#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {

	stringstream ss;
	string s = "suck?my?dick";
	string token;
	ss << s;
	while (getline(ss, token, '?')) {
		cout << token << endl;
	}
	return 0;
}