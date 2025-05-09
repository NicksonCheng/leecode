/*
    1. stack 作法，, time: O(n), space: O(n)
    open 不夠時, star來補充

    close不夠時, 如果star idx > open 才能補充


    2. greedy 作法: 因為每次star都會產生
*/
class Solution {
  public:
	bool checkValidString(string s) {
		stack<int> open;
		stack<int> star;

		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '(')
				open.push(i);
			else if (s[i] == ')') {
				if (open.empty()) {

					if (star.empty())
						return false;
					// star be '('
					else
						star.pop();
				} else
					open.pop();
			} else {
				star.push(i);
			}
		}

		while (!open.empty()) {
			if (star.empty() || star.top() < open.top())
				return false;
			star.pop();
			open.pop();
		}
		return true;
	}
};

/* greedy */
class Solution {
  public:
	bool checkValidString(string s) {
		int low = 0, high = 0; // worst # '(' and best # '('

		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '(') {
				++low;
				++high;
			} else if (s[i] == ')') {
				--low;
				--high;
			} else {
				--low;  // be ')'
				++high; // be '('
			}

			// 最佳# open居然是 < 0 代表加上*變成open都會 < close數量
			if (high < 0)
				return false;

			// 如果最佳open > 0 那最差open 不能 < 0, 因爲*可以做為""
			low = max(low, 0);
		}

		// 查看最差是否為0
		return low == 0;
	}
};