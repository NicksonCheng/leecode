/*
    1. 搞懂題目: 題目的意思在於能否找到最小的subarray,
   讓我們sort這個subarray就可以sorting整個array

    2. 作法
        1. Brutal force: 每個subarray 都去check 是否是acending order,
   然後找最小的subarry, time complexity O(n^3)

        3. monotonic stack正確做法, 左到右acending check, 右到左descending
   check, right - left 為answer

        4, two pointer作法 time O(n), space O(1)


*/
class Solution {
  public:
	int findUnsortedSubarray(vector<int> &nums) {
		int n = nums.size();
		stack<int> ascend_ms;
		stack<int> descend_ms;
		int right = 0;
		int left = n - 1;
		for (int i = 0; i < n; ++i) {
			while (!ascend_ms.empty() && nums[ascend_ms.top()] > nums[i]) {
				left = min(ascend_ms.top(), left);
				ascend_ms.pop();
			}
			ascend_ms.push(i);
		}
		if (left == n - 1)
			return 0; // already sort

		for (int i = n - 1; i >= 0; --i) {
			while (!descend_ms.empty() && nums[descend_ms.top()] < nums[i]) {
				right = max(descend_ms.top(), right);
				descend_ms.pop();
			}
			descend_ms.push(i);
		}
		return right - left + 1;
	}
};