/*
    sol.1 : another vector to store update array, time O(n), space O(n)
    sol.2 : 按照k次rotate去swap, time O(n * K)
    sol.3 : 每次num[next] 都跟nums[i] 交換, 直到跑完一個cycle, count == n
   代表所有node都跑過了 time O(n) space O(1) sol.4 三次反轉, two pointer, time
   O(n) space O(1)
*/
class Solution {
  public:
	void rotate(vector<int> &nums, int k) {
		int n = nums.size();
		int count = 0;
		for (int i = 0; count < n; ++i) {
			int start = i;
			int cur = i;
			do {
				int next = (cur + k) % n;
				swap(nums[start], nums[next]);
				cur = next;
				++count;
			} while (cur != start);
		}
	}
};