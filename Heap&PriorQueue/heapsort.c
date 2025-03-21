#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void heapify(int *arr, int n, int i) {
	int largest_idx = i;
	int left_idx = 2 * i + 1;
	int right_idx = 2 * i + 2;

	if (left_idx < n && arr[left_idx] > arr[largest_idx])
		largest_idx = left_idx;
	if (right_idx < n && arr[right_idx] > arr[largest_idx])
		largest_idx = right_idx;

	// this root node is not largest
	if (largest_idx != i) {
		swap(&arr[i], &arr[largest_idx]);

		// compared next subtree to put this root into right position in max
		// heap
		heapify(arr, n, largest_idx);
	}
}
void heapSort(int *arr, int n) {
	// buttom-up from non-leaf node build max heap
	for (int i = n / 2 - 1; i >= 0; --i) {
		heapify(arr, n, i);
	}
	printf("heap sort success\n");
	/*
	    Extract elements from heap one by one
	    keep swap last element and root node, and rearrange max heap
	*/

	for (int i = n - 1; i >= 0; --i) {
		swap(&arr[i], &arr[0]);
		heapify(arr, i, 0);
	}
}
void printArray(int *arr, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main(int argc, char *argv[]) {
	int arr[] = {10, 30, 20, 5, 1, 50, 40};
	int n = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, n);
	heapSort(arr, n);
	printArray(arr, n);

	return 0;
}