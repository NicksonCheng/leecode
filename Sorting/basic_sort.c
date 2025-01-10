#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
void printArray(int *array, int length) {
  for (int i = 0; i < length; ++i) {
    printf("%d ", array[i]);
  }
  printf(", length: %d", length);
  printf("\n");
}
void insertionSort(int *target_array, int length) {
  for (int i = 1; i < length; ++i) {
    int j = i - 1;
    int key = target_array[i];
    while (j >= 0 && key < target_array[j]) {
      /* code */
      target_array[j + 1] = target_array[j]; // push array from j to j+1
      --j;
    }
    target_array[j + 1] = key;
  }
}
int partition(int *target_array, int begin, int end) {

  // just find the position that left nums smaller than pivot, right nums larger
  // that pivot could choice pivot in the end directly
  int medium = begin + (end - begin) / 2;
  int pivot = target_array[medium];
  swap(&target_array[medium], &target_array[end - 1]); // move pivot to end
  int i = begin - 1;
  for (int j = begin; j < end - 1; ++j) {
    if (target_array[j] < pivot) { // find the position index i
      ++i;
      swap(&target_array[i], &target_array[j]);
    }
  }

  // remember index i+1 is right pivot we replace
  swap(&target_array[i + 1], &target_array[end - 1]);
  return i + 1;
}
void quickSort(int *target_array, int begin, int end) {

  if (begin < end) {
    int pivot = partition(target_array, begin, end);
    quickSort(target_array, begin, pivot - 1);
    quickSort(target_array, pivot + 1, end);
  }
}

int *heapify(int *target_array, int n, int i) { /*maximize heap*/ }
int *heapSort(int *target_array, int n) {

  // Build Heaps
  for (int i = n / 2 - 1; i >= 0; --i) {
    heapify(target_array, n, i);
  }
  // remove last
}

int main(int argc, char *argv[]) {

  int arr_len = argc - 1;
  int *arr = (int *)malloc(sizeof(int) * arr_len);
  for (int i = 0; i < arr_len; ++i)
    arr[i] = atoi(argv[i + 1]);

  printf("Before: ");
  printArray(arr, arr_len);
  // insertionSort(arr,arr_len);
  quickSort(arr, 0, arr_len);
  printf("After: ");
  printArray(arr, arr_len);

  return 0;
}