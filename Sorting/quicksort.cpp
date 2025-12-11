#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
int partition(vector<int> &arr, int begin, int end) {
	int pivot = arr[end]; // used last element as pivot
	int j = begin;        // 最後pivot放的位置
	for (int i = begin; i < end; ++i) {
		// 比pivot 小的放左邊
		if (arr[i] < pivot) {
			swap(arr[i], arr[j]); // 將這個比較小的值move到pivot左邊
			++j;                  // move pivot
		}
	}
	swap(arr[end], arr[j]); // 最後pivot放位置
	return j;
}
void quicksort(vector<int> &arr, int begin, int end) {
	if (begin < end) {
		int mid =
		    partition(arr, begin, end); // sort curruent [begin, end] array
		quicksort(arr, begin, mid - 1); // sort left subarray
		quicksort(arr, mid + 1, end);   // sort right subarray
	}
}
int main() {
	vector<int> arr = {3, 5, 7, 1, 2, 8, 9};
	quicksort(arr, 0, arr.size() - 1);
	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}