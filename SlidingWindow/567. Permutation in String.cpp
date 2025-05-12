/*
    vector<int,26> 紀錄每個char的次數
    sliding window不斷動態更新
*/
class Solution {
  public:
	bool checkInclusion(string s1, string s2) {
		vector<int> count(26, 0);

		for (int i = 0; i < s1.length(); ++i)
			++count[s1[i] - 'a'];

		int l = 0;
		for (int r = 0; r < s2.length(); ++r) {
			--count[s2[r] - 'a'];
			if (r - l + 1 == s1.length()) {
				if (allzero(count))
					return true;
				++count[s2[l] - 'a'];
				++l;
			}
		}
		return false;
	}
	bool allzero(vector<int> &count) {
		for (int i = 0; i < count.size(); ++i) {
			if (count[i] != 0)
				return false;
		}
		return true;
	}
};