#include <iostream>
#include <vector>
using namespace std;

// Selection Sort 函式
void selectionSort(vector<int> &arr) {
	int n = arr.size();

	for (int i = 0; i < n - 1; i++) {
		// 假設目前 i 位置是最小值
		int minIndex = i;

		// 從 i+1 到 n-1 找最小值
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}

		// 如果找到比 i 小的值，交換
		if (minIndex != i) {
			swap(arr[i], arr[minIndex]);
		}
	}
}

int main() {
	vector<int> arr = {64, 25, 12, 22, 11};

	cout << "原始陣列: ";
	for (int num : arr)
		cout << num << " ";
	cout << endl;

	selectionSort(arr);

	cout << "排序後陣列: ";
	for (int num : arr)
		cout << num << " ";
	cout << endl;

	return 0;
}
