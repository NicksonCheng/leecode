#include <iostream>
#include <vector>
using namespace std;

// 合併兩個已排序子陣列 arr[l..m] 和 arr[m+1..r]
void merge(vector<int> &arr, int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	vector<int> L(n1);
	vector<int> R(n2);

	// 複製資料到臨時陣列
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int i = 0; i < n2; i++)
		R[i] = arr[m + 1 + i];

	int i = 0, j = 0, k = l;

	// 合併回原陣列
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k++] = L[i++];
		} else {
			arr[k++] = R[j++];
		}
	}

	// 複製剩餘元素
	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = R[j++];
}

// Merge Sort 主函式
void mergeSort(vector<int> &arr, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2; // 避免溢位
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int main() {
	vector<int> arr = {12, 11, 13, 5, 6, 7};

	cout << "原始陣列: ";
	for (int num : arr)
		cout << num << " ";
	cout << endl;

	mergeSort(arr, 0, arr.size() - 1);

	cout << "排序後陣列: ";
	for (int num : arr)
		cout << num << " ";
	cout << endl;

	return 0;
}
