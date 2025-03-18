#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
	int evalRPN(vector<string> &tokens) {
		stack<string> s;
		string op = "+-*/";
		for (auto &t : tokens) {
			if (op.find(t) == string::npos) {
				// number
				s.push(t);
			} else {
				int n2 = stoi(s.top());
				s.pop();
				int n1 = stoi(s.top());
				s.pop();
				int res = 0;
				if (t == "+")
					res = n1 + n2;
				else if (t == "-")
					res = n1 - n2;
				else if (t == "*")
					res = n1 * n2;
				else if (t == "/")
					res = n1 / n2;
				s.push(to_string(res));
			}
		}
		return stoi(s.top());
	}
};

int main() {
	vector<string> tokens = {"1", "2", "+", "3", "*", "4", "-"};
	Solution sol;
	int res = sol.evalRPN(tokens);
	cout << res << endl;
	return 0;
}