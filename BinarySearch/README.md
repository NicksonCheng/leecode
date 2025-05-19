# Binary Search

binary search 不一定只用來找「某個值」，更強大的是：

它可以找出「最早」或「最晚」符合條件的元素。
這就是 lower_bound / upper_bound 存在的理由。
lower_bound(nums.begin(), nums.end(), x)
👉 找第一個 ≥ x 的元素

upper_bound(nums.begin(), nums.end(), x)
👉 找第一個 > x 的元素

### 34. Find First and Last Position of Element in Sorted Array

lower bound, upper bound 問題
可能 R 已經找到讓他-1 沒有關係, L == R check 之後 L 會再+1 到達剛剛要找的值

### 153.Find Minimum Rotated Sorted Array

Sol 1: Binary Search

1. 一樣我們定義 left, right 的 pivot 去重複找 middle binary search
2. 但這次我們以 array 最後一個值作為基準點, 比 array[n-1]大表示這個 array 有被 rotate 過最小值必在右邊, 反之最小值必在左邊
