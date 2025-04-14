// hint
/*1. 先sort之後, 然後loop 去計算重複出現的次數有沒有> n/2, 但time complexity 為
O(nlogn)
2. Boyer–Moore majority vote algorithm 自爆戰術, 每次抓兩個不同number去刪除,
因為一定有一個majority element, 所以最後必定能刪到剩下majority
*/
class Solution {
  public:
	int majorityElement(vector<int> &nums) {
		int majority_cnt = 0;
		int majority_num = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (majority_cnt == 0) {
				majority_num = nums[i];
				++majority_cnt;
			} else {
				if (nums[i] != majority_num) {
					// 抵銷
					--majority_cnt;
				} else {
					++majority_cnt;
				}
			}
		}
		return majority_num;
	}
};