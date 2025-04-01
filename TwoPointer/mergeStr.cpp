// proficient
class Solution {
  public:
	string mergeAlternately(string word1, string word2) {
		string res;
		int i1 = 0;
		int i2 = 0;
		int n1 = word1.length();
		int n2 = word2.length();
		while (i1 < n1 && i2 < n2) {
			res.push_back(word1[i1]);
			res.push_back(word2[i2]);
			++i1;
			++i2;
		}
		while (i1 < n1) {
			res.push_back(word1[i1]);
			++i1;
		}
		while (i2 < n2) {
			res.push_back(word2[i2]);
			++i2;
		}
		return res;
	}
};