#include <iostream>
#include <vector>
using namespace std;

// 將 arr[i..n-1] 調整成最大堆
void heapify(vector<int> &arr, int n, int i) {
	int largest = i;       // 假設 i 是最大值
	int left = 2 * i + 1;  // 左子節點
	int right = 2 * i + 2; // 右子節點

	// 找左右子節點中最大的
	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;

	// 如果最大值不是 i，交換並遞迴
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

// Heap Sort 主函式
void heapSort(vector<int> &arr) {
	int n = arr.size();

	// 建立最大堆
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	// 一個個取出最大值到尾端
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]); // 將堆頂最大值移到末尾
		heapify(arr, i, 0);   // 調整剩下的堆
	}
}

int main() {
	vector<int> arr = {12, 11, 13, 5, 6, 7};

	cout << "原始陣列: ";
	for (int num : arr)
		cout << num << " ";
	cout << endl;

	heapSort(arr);

	cout << "排序後陣列: ";
	for (int num : arr)
		cout << num << " ";
	cout << endl;

	return 0;
}
