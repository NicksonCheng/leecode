// proficient
/*
先建立vector<set<int>> 儲存每個number所代表的character
然後recursive 去找到所有組合
*/
#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
  public:
	vector<vector<char>> table = {
	    {},
	    {'a', 'b', 'c'},      // 2
	    {'d', 'e', 'f'},      // 3
	    {'g', 'h', 'i'},      // 4
	    {'j', 'k', 'l'},      // 5
	    {'m', 'n', 'o'},      // 6
	    {'p', 'q', 'r', 's'}, // 7
	    {'t', 'u', 'v'},      // 8
	    {'w', 'x', 'y', 'z'}  // 9p
	};
	vector<string> res;
	vector<string> letterCombinations(string digits) {
		if (digits.length() == 0)
			return {};
		dfs(digits, "", 0);
		return res;
	}
	void dfs(string &digits, string word, int i) {
		if (i == digits.length()) {
			res.push_back(word);
			return;
		}
		int d = (digits[i] - '0') - 1;
		for (char &c : table[d]) {
			dfs(digits, word + c, i + 1);
		}
	}
};