# Binary Search

### 153.Find Minimum Rotated Sorted Array

Sol 1: Binary Search

1. 一樣我們定義 left, right 的 pivot 去重複找 middle binary search
2. 但這次我們以 array 最後一個值作為基準點, 比 array[n-1]大表示這個 array 有被 rotate 過最小值必在右邊, 反之最小值必在左邊
