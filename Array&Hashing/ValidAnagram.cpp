#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
  public:
	bool isAnagram(string s, string t) {
		if (s.length() > t.length())
			return false;
		unordered_map<char, int> visit_map;
		for (int i = 0; i < s.length(); ++i) {
			char c = s[i];
			if (visit_map.find(c) == visit_map.end())
				visit_map[c] = 1;
			else
				++visit_map[c];
		}
		for (int i = 0; i < t.length(); ++i) {

			char c = t[i];
			if (visit_map.find(c) == visit_map.end())
				return false;
			else
				--visit_map[c];
		}
		for (const auto &is_visit : visit_map) {
			if (is_visit.second > 0)
				return false;
		}
		return true;
	}
};

int main() {
	Solution sol;
	string s = "a";
	string t = "ab";
	cout << sol.isAnagram(s, t) << endl;
	return 0;
}