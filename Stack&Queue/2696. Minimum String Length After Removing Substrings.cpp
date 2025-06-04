/*
    兩兩抵銷-> stack

    O(n), 每個char 只會push/pop一次
*/
class Solution {
  public:
	int minLength(string s) {
		stack<int> st;

		for (char &c : s) {

			if (!st.empty() && ((c == 'B' && st.top() == 'A') ||
			                    (c == 'D' && st.top() == 'C')))
				st.pop();
			else
				st.push(c);
		}
		return st.size();
	}
};