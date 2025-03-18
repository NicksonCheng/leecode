#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;
class Solution {
  public:
	bool isValid(string s) {
		stack<char> parentheses_stack;
		map<char, char> parentheses_map;
		parentheses_map['('] = ')';
		parentheses_map['['] = ']';
		parentheses_map['{'] = '}';
		vector<char> left = {'(', '[', '{'};
		vector<char> right = {')', ']', '}'};
		for (int i = 0; i < s.length(); ++i) {
			// left parentheses
			if (find(left.begin(), left.end(), s[i]) != left.end()) {

				parentheses_stack.push(s[i]);
				continue;
			}

			// right parentheses
			if (parentheses_stack.empty())
				return false;
			char top_parentheses = parentheses_stack.top();
			if (parentheses_map[top_parentheses] != s[i]) {
				return false;
			} else {
				parentheses_stack.pop();
			}
		}
		if (!parentheses_stack.empty())
			return false;
		return true;
	};
};
int main() {
	Solution sol;
	string str = "()[]{}";
	cout << sol.isValid(str) << endl;
	return 0;
}