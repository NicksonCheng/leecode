// solutioon
/*
維護目前剩餘字元中最小的那一個，當 stack 頂端 ≤
目前剩下未處理字元的最小字元時，才可以輸出 stack.top()。

    先處理每個s[i] 右邊的最小char, min_suffix

    traverse s, stack.top() < min_suffix[i], 就將其pop出來(自己已經是最小)
    不然就push s[i] 進去stack

    push/pop stack 一次 time O(n), space O(n)
*/
class Solution {
  public:
	string robotWithString(string s) {
		int n = s.size();
		vector<char> min_suffix(n);
		stack<char> st;
		string res = "";
		min_suffix[n - 1] = s[n - 1];
		for (int i = n - 2; i >= 0; --i)
			min_suffix[i] = min(s[i], min_suffix[i + 1]);
		for (int i = 0; i < s.length(); ++i) {
			while (!st.empty() && st.top() <= min_suffix[i]) {
				res += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
		// clear rest stack
		while (!st.empty()) {
			res += st.top();
			st.pop();
		}
		return res;
	}
};