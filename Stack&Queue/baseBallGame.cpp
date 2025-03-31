// proficient
// LeetCode 682.
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
	int calPoints(vector<string> &operations) {
		stack<int> scores;
		for (string &ops : operations) {
			if (ops == "C") {
				if (scores.empty())
					continue;
				scores.pop();
			} else if (ops == "D") {
				if (scores.empty())
					continue;
				int num = scores.top() * 2;
				scores.push(num);
			} else if (ops == "+") {
				if (scores.size() < 2)
					continue;
				int s1 = scores.top();
				scores.pop();
				int s2 = scores.top();
				scores.pop();
				int s3 = s1 + s2;
				scores.push(s2);
				scores.push(s1);
				scores.push(s3);
			} else {

				int score = stoi(ops);
				// cout << ops << " " << score << endl;
				scores.push(score);
			}
		}
		int sum = 0;
		while (!scores.empty()) {
			cout << scores.top() << endl;
			sum += scores.top();
			scores.pop();
		}
		return sum;
	}
};

int main() {
	vector<string> ops = {"5", "-2", "4", "C", "D", "9", "+", "+"};
	Solution sol;
	cout << sol.calPoints(ops) << endl;
	return 0;
}