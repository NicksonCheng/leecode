/*
    我們只挑那些「不超過 target」的 triplet，然後每一維都盡可能貢獻出 target
   的值。
*/
class Solution {
  public:
	bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
		vector<bool> found(3, false); // 每一維是否 match target

		for (auto &t : triplets) {
			bool valid = true;
			for (int i = 0; i < 3; ++i) {
				if (t[i] > target[i]) {
					valid = false;
					break;
				}
			}

			if (!valid)
				continue;

			for (int i = 0; i < 3; ++i) {
				if (t[i] == target[i])
					found[i] = true;
			}
		}

		return found[0] && found[1] && found[2];
	}
};
