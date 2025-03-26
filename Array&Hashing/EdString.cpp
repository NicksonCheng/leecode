#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
	vector<int> breakpoint;
	string encode(vector<string> &strs) {
		string res = "";
		int bp = 0;
		breakpoint.push_back(bp);
		for (int i = 0; i < strs.size(); ++i) {
			res += strs[i];
			bp += strs[i].length();
			breakpoint.push_back(bp);
		}
		return res;
	}

	vector<string> decode(string s) {
		vector<string> res2;

		for (int i = 0; i < breakpoint.size() - 1; ++i) {
			int start = breakpoint[i];
			int end = breakpoint[i + 1];
			res2.push_back(s.substr(start, end - start));
		}
		return res2;
	}
};

int main() {
	vector<string> strs = {"neet", "code", "love", "you"};
	Solution sol;
	string e = sol.encode(strs);
	vector<string> d = sol.decode(e);

	for (string dd : d) {
		cout << dd << endl;
	}
}