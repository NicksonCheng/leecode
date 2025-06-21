// proficient
/*
    question is divide the subseqence, and each num[i] is used once exactly
    our target: find minimum number of subsequence need for the max element -
   min element <= k

    sol.2 greedy, add more to subsequence is better, O(n), space O(1)
*/
class Solution {
  public:
	int partitionArray(vector<int> &nums, int k) {
		sort(nums.begin(), nums.end());
		int num_subseq = 0;
		int min_val = nums[0]; // the is to record the minimum value in current
		                       // subsequence
		for (int i = 1; i < nums.size(); ++i) {
			// seperate the subsequence
			if (nums[i] - min_val > k) {
				++num_subseq;
				min_val = nums[i];
			}
		}
		// we still need to add last subsequence
		++num_subseq;
		return num_subseq;
	}
};