/*
    先看distinct char num, 也就是at least num i, 每次nums[i + 1] = nums[i] + num
   rest char in hashtable

    n = word.size
    at least k = prefix[n - 1] - prefix[k]
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
	int possibleStringCount(string word, int k) {
		int n = word.length();
		int num_dis = 0;
		vector<int> prefix(n, 0);
		vector<char> num_chars(26, 0);
		for (char &c : word) {
			if (num_chars[c] == 0)
				++num_dis;
			++num_chars[c];
		}
		for (int i = num_dis; i < n; ++i) {
			prefix[i] = prefix[i - 1];
			for (int j = 0; j < 26; ++j) {
				if (num_chars[j] > 0) {
					--num_chars[j];
					++prefix[i];
				}
			}
		}
		return prefix[n - 1] - prefix[k];
	}
};