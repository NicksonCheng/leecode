#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void bubble_sort(vector<int> &arr, int n) {
	// the end is ready maximum, find next by i - 1
	for (int i = n - 1; i >= 0; --i) {
		// bubble float the maximum value to the end
		for (int j = 1; j <= i; ++j) {
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
		}
	}
}
int main() {
	vector<int> arr = {3, 5, 7, 1, 2, 8, 9};
	bubble_sort(arr, arr.size());
	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}