#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void insertion_sort(vector<int> &arr, int n) {
	/* in each element i, iterate back [i - 1, 0], find approriate position to
	 * insert value*/
	for (int i = 1; i < n; ++i) {
		int num = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > num) {
			arr[j + 1] = arr[j]; // push back
			--j;
		}
		// final j + 1 is the position to insert num
		arr[j + 1] = num;
	}
}
int main() {
	vector<int> arr = {3, 5, 7, 1, 2, 8, 9};
	insertion_sort(arr, arr.size());
	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}