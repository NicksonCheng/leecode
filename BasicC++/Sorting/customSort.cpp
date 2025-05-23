#include <iostream>
#include <vector>
using namespace std;
bool cmp(int a, int b) {
	// descending order
	return a > b;
}

int main() {
	vector<int> arr = {3, 1, 5, 7, 6};
	sort(arr.begin(), arr.end());

	for (int a : arr) {
		cout << a << " ";
	}
	cout << endl;
}