/*
    sliding window
    hashtable紀錄char in t出現次數
    另一個hashtable check char in s[i]是否滿足hashtable t的要求

    當全數滿足 form(s) = target(t), 就去縮小windows直到不滿足

    time complexity O(n)
*/
class Solution {
  public:
	string minWindow(string s, string t) {
		unordered_map<char, int> s_map;
		unordered_map<char, int> t_map;
		int correspond = 0;
		int num_dis_char = 0;
		int l = 0;
		pair<int, int> min_w = {-1, INT_MAX};
		for (char &c : t) {
			if (t_map.count(c) == 0)
				++num_dis_char;
			++t_map[c];
		}

		for (int r = 0; r < s.length(); ++r) {
			char c = s[r];
			++s_map[c];

			if (s_map[c] == t_map[c])
				++correspond;
			while (correspond == num_dis_char) {
				// narrow down windows
				char l_c = s[l];
				--s_map[l_c];

				if (s_map[l_c] < t_map[l_c]) {
					// 不再符合t_map
					--correspond;
					// count mini window
					int w = r - l + 1;
					if (w < min_w.second) {
						min_w = {l, w};
					}
				}
				++l;
			}
		}
		if (min_w.second == INT_MAX)
			return "";
		else
			return s.substr(min_w.first, min_w.second);
	}
};