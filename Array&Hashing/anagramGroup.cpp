/* My solution

*/

class Solution {
  public:
	vector<vector<string>> groupAnagrams(vector<string> &strs) {
		vector<vector<string>> anagram_group;
		for (int i = 0; i < strs.size(); ++i) {
			string s = strs[i];
			bool new_s = true;
			unordered_map<char, int> cnt_map;
			for (int j = 0; j < s.length(); ++j)
				++cnt_map[s[j]];
			for (int j = 0; j < anagram_group.size(); ++j) {
				string cmp_str = anagram_group[j][0];
				unordered_map<char, int> cnt_map2;
				for (int k = 0; k < cmp_str.size(); ++k) {
					++cnt_map2[cmp_str[k]];
				}
				if (cnt_map == cnt_map2) {
					anagram_group[j].push_back(s);
					new_s = false;
				}
			}
			if (new_s) {
				vector<string> new_g;
				new_g.push_back(s);
				anagram_group.push_back(new_g);
			}
		}
		return anagram_group;
	}
};

/* Best Solution
 */

class Solution {
  public:
	vector<vector<string>> groupAnagrams(vector<string> &strs) {
		unordered_map<string, vector<string>> res;
		for (const auto &s : strs) {
			vector<int> count(26, 0);
			for (char c : s) {
				count[c - 'a']++;
			}
			string key = to_string(count[0]);
			for (int i = 1; i < 26; ++i) {
				key += ',' + to_string(count[i]);
			}
			res[key].push_back(s);
		}
		vector<vector<string>> result;
		for (const auto &pair : res) {
			result.push_back(pair.second);
		}
		return result;
	}
};