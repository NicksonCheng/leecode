
/*
    1. 每次backtracking看能不能跳完, 可以就回傳true, time complexity為O(n!)
    2. 從後面往回看, 尋找可以跳完的index, 再從這個index往前看誰可以跳到他,
   最後index 0為true則jump ture time complexity 為O(n)
*/
class Solution {
  public:
	bool canJump(vector<int> &nums) {
		int canjump_idx = nums.size() - 1;
		for (int i = nums.size() - 2; i >= 0; --i) {
			// update can jump index
			if (i + nums[i] >= canjump_idx)
				canjump_idx = i;
		}
		return canjump_idx == 0;
	}
};
