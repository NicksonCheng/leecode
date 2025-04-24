/*
    1. 先用set去看array distinct number, sliding window 確認目前這個[l,r]
   是否distinct number一樣, O(n^2)

    2. slding window, 先滑動右邊, 直到==distinct number,
   這時right右邊的subarray都是合法的, 這時再滑動左邊查看是否還是合法
*/
class Solution {
  public:
	int countCompleteSubarrays(vector<int> &nums) {
		int count = 0;
		set<int> distinct_num;
		unordered_map<int, int> subarr_count;
		for (int &n : nums)
			distinct_num.insert(n);
		int l = 0;
		for (int r = 0; r < nums.size(); ++r) {
			++subarr_count[nums[r]];
			while (subarr_count.size() == distinct_num.size()) {
				count += nums.size() - r;
				--subarr_count[nums[l]];
				if (subarr_count[nums[l]] == 0)
					subarr_count.erase(nums[l]);
				++l;
			}
		}
		return count;
	}
};

class Solution {
  public:
	int countCompleteSubarrays(vector<int> &nums) {
		int count = 0;
		set<int> distinct_num;
		unordered_map<int, int> subarr_count;
		for (int &n : nums)
			distinct_num.insert(n);
		int l = 0;
		for (int r = 0; r < nums.size(); ++r) {
			++subarr_count[nums[r]];
			while (subarr_count.size() == distinct_num.size()) {
				count += nums.size() - r;
				--subarr_count[nums[l]];
				if (subarr_count[nums[l]] == 0)
					subarr_count.erase(nums[l]);
				++l;
			}
		}
		return count;
	}
};