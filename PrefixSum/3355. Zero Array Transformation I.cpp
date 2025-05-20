// solution
/*
    sol.1. brutal force, decrease input nums by every queries, if there is no
   element > 0 in nums, return true time: O(n^2*m), space O(1) n = nums.length,
   m = queries.length

    sol.2 hashtable save each indices decrement number, and decrease the num by
   hashtable, because we need to traverse queries subset, time O(n^2) space O(n)

    sol.3 prefix_sum + difference array, 透過對[l...r] 區間去計算diff, 讓prefix
   sum 決定目前這個i 要decrese幾次, time O(n), space: O(n) [0,2] [1,3] diff =
   [1,0,1,-1,-1]
*/
class Solution {
  public:
	bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
		vector<int> diff(nums.size() + 1, 0);
		for (auto &q : queries) {
			int l = q[0];
			int r = q[1];
			++diff[l];
			--diff[r + 1];
		}
		int num_decrease = 0;
		for (int i = 0; i < nums.size(); ++i) {
			num_decrease += diff[i];
			if (nums[i] > num_decrease)
				return false;
		}
		return true;
	}
};