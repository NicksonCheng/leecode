/*
    1. 從頭開始跳
    2. 每次都從l~r的某一點跳找最遠能跳到哪裡去, 然後更新最遠的值到right
    3. left更新到r+1;
    4. 跳的值+1(代表這次iteration已經跳完)
    5. r 到達最尾端就跳完
*/
class Solution {
  public:
	int jump(vector<int> &nums) {
		int l = 0;
		int r = 0;
		int res = 0;
		while (r < nums.size() - 1) {
			int farest_jump_idx = 0;
			for (int i = l; i <= r; ++i) {
				farest_jump_idx = max(farest_jump_idx, nums[i] + i);
			}

			l = r + 1;
			r = farest_jump_idx;
			++res;
		}
		return res;
	}
};
