/*
    記得跳過那些重複的candidate就好
*/
class Solution {
  public:
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {

		sort(candidates.begin(), candidates.end());
		vector<int> combination;
		recursive(candidates, combination, target, 0);
		return res;
	}

  private:
	vector<vector<int>> res;
	void recursive(vector<int> &candidates, vector<int> &combination,
	               int target, int i) {
		if (target <= 0 || i == candidates.size()) {
			if (target == 0)
				res.push_back(combination);
			return;
		}
		int num = candidates[i];
		combination.push_back(num);
		recursive(candidates, combination, target - num, i + 1);
		combination.pop_back();
		while (num == candidates[i + 1])
			++i;
		recursive(candidates, combination, target, i + 1);
	}
};