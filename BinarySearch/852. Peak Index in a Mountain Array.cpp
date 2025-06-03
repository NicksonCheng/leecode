// proficient
/*
    Binary Search看左右兩邊, left/right 往大的那邊移動, 兩邊都比較小,
   自己就是peak time O(logn)
*/
class Solution {
  public:
	int peakIndexInMountainArray(vector<int> &arr) {
		int l = 0;
		int r = arr.size() - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (arr[m + 1] > arr[m])
				l = m + 1;
			else if (arr[m - 1] > arr[m])
				r = m - 1;
			else {
				// middle is peak element
				return m;
			}
		}
		// cout << "execute here" << endl;
		return l;
	}
};