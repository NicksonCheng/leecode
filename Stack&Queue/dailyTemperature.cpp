/*1. 問題在找下一個比自己大element在哪裡, 暴力法就是每個element都往後loop
search, 但這樣的time complexity 為O(n^2)
2. 我們可以採取stack的做法, 從後面開始, 如果element i 比stack.top還小,
就直接push進去, 比stack.top還大就不斷pop直到遇到比自己還大的element
3. 額外step variable去紀錄pop了幾次就是 ith day warmer temperature
4. 乍看之下兩個loop會是O(n^2), 但是element一但pop出去就不再visit, worse
case就是2n, 也就是O(n)
*/
class Solution {
  public:
	vector<int> dailyTemperatures(vector<int> &temperatures) {
		stack<int> s; // push index
		int n = temperatures.size();
		vector<int> res(n, 0);
		for (int i = n - 1; i >= 0; --i) {
			int t = temperatures[i];
			int step = 0;
			while (!s.empty()) {
				int idx = s.top();
				if (t >= temperatures[idx]) {
					s.pop();
				} else {
					step = idx - i;
					break;
				}
			}
			res[i] = step;
			s.push(i);
		}
		return res;
	}
};
