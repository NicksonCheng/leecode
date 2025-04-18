#include <iostream>
using namespace std;
int main() {
	int x = 10;
	auto lambda = [x]() { cout << x << endl; };
	auto lambda2 = [&x]() { x += 5; };
	lambda();
	lambda2();
	cout << x << endl;
}