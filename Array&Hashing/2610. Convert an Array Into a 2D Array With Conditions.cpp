/*
    sol.1
    minimal rows == max count in nums

    set<int> 儲存distince num, 如果每個set都exist 就開新的set, 最後set
   轉成vector

    time complexity O(n^2)


    sol.2 hashtable 紀錄nums[i] 出現次數, 然後將其分配至每個vector<int> 即可
    time O(n)
*/
class Solution {
  public:
	vector<vector<int>> findMatrix(vector<int> &nums) {
		vector<unordered_set<int>> dis_nums;
		vector<vector<int>> res;
		for (int &num : nums) {
			bool all_exist = true;
			for (auto &s : dis_nums) {
				if (s.count(num) == 0) {
					s.insert(num);
					all_exist = false;
					break;
				}
			}
			if (all_exist)
				dis_nums.push_back({num});
		}
		for (auto &s : dis_nums) {
			vector<int> ns(s.begin(), s.end());
			res.push_back(ns);
		}
		return res;
	}
};
/*
    sol.1
    minimal rows == max count in nums

    set<int> 儲存distince num, 如果每個set都exist 就開新的set, 最後set
   轉成vector

    time complexity O(n^2)


    sol.2 hashtable 紀錄nums[i] 出現次數, 然後將其分配至每個vector<int> 即可
    time O(n)
*/
class Solution {
  public:
	vector<vector<int>> findMatrix(vector<int> &nums) {
		unordered_map<int, int> num_count;
		vector<vector<int>> res;
		for (int i = 0; i < nums.size(); ++i) {
			int num = nums[i];
			int nc = num_count[num]++;

			if (nc >= res.size())
				res.push_back({num});
			else
				res[nc].push_back(num);
		}
		return res;
	}
};