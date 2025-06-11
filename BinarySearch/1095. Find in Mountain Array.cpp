// proficient
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
/*
    先找到 binary search peak, 然後正常binary search 兩邊直到找到target
*/
class Solution {
  public:
	int findInMountainArray(int target, MountainArray &mountainArr) {
		int l = 0;
		int r = mountainArr.length() - 1;
		int peak;
		// find peak first
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (mountainArr.get(m) < mountainArr.get(m + 1))
				l = m + 1;
			else if (mountainArr.get(m) < mountainArr.get(m - 1))
				r = m - 1;
			else {
				peak = m;
				break;
			}
		}
		int target_idx = -1;
		// find target in right side
		l = peak;
		r = mountainArr.length() - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (target < mountainArr.get(m))
				l = m + 1;
			else if (target > mountainArr.get(m))
				r = m - 1;
			else {
				target_idx = m;
				break;
			}
		}
		// find target in left side
		l = 0;
		r = peak;
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (target > mountainArr.get(m))
				l = m + 1;
			else if (target < mountainArr.get(m))
				r = m - 1;
			else {
				target_idx = m;
				break;
			}
		}
		return target_idx;
	}
};