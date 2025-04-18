/*1. 暴力法兩次loop每個element去查看duplicated的distance是否<= k O(n^2)
2. 先sort再two pointer看duplicated部分有沒有 <= k O(nlogn)
3. 每次都去儲存nums[i] 的 index i, 當再遇到他時如果目前index跟他的index
distance<=k 就是true, > k就更新nums[i]的index繼續比較, O(n), space O(n)
*/
class Solution {
  public:
	bool containsNearbyDuplicate(vector<int> &nums, int k) {
		unordered_map<int, int> num_idx;

		for (int i = 0; i < nums.size(); ++i) {
			if (num_idx.find(nums[i]) != num_idx.end() &&
			    i - num_idx[nums[i]] <= k) {
				return true;
			}
			num_idx[nums[i]] = i;
		}
		return false;
	}
};