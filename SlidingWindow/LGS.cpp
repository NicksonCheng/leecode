#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {

  public:
	int lengthOfLongestSubstring(string s) {
		int l = 0, r = 0;
		map<char, bool> char_map;
		int max_len = 0;
		while (r < s.size()) {
			char cur_char = s[r];
			if (char_map.find(s[r]) == char_map.end()) {
				char_map[s[r]] = true;
				int len = r - l + 1;
				if (len > max_len)
					max_len = len;
				++r;
			} else {
				char_map.erase(s[l]);
				++l;
			}
		}
		return max_len;
	}
};

int main() {
	Solution sol;
	string str = "pwwkew";
	cout << sol.lengthOfLongestSubstring(str) << endl;
}