#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
	/*1. used sliding windows
	  2. replace less frequent char
	  3. if replacement exceed k, move left
	  4. find maximum windows in each iteration
	  5. time complexity is O(N)*/
  public:
	int characterReplacement(string s, int k) {
		map<char, int> char_cnt;
		int l = 0, max_len = 0;
		int res = 0;
		for (int r = 0; r < s.size(); ++r) {
			++char_cnt[s[r]];
			max_len = max(max_len, char_cnt[s[r]]);

			int curr_sub_len = r - l + 1;
			while (curr_sub_len - max_len > k) {
				--char_cnt[s[l]];
				++l;
				curr_sub_len = r - l + 1;
			}

			res = max(curr_sub_len, res);
		}
		return res;
	}
};

int main() {
	Solution sol;
	string str = "XYYXYYYX";
	cout << sol.characterReplacement(str, 2) << endl;
}