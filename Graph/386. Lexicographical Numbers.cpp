// 超時
/*
    DFS + Tries
    先1 ~ 9 每個digits都確認一遍
    透過recursive 先 dfs 到最大位數, 然後再處理每個位數後面的數字

                1   2   3   ... 9
              / |   |   |
            10 11  20  21 ...
           /       ...
         100     ...

*/
class Solution {
  public:
	void mutliplyDigits(vector<int> &res, int n, int base) {

		for (int i = 0; i <= 9; ++i) {
			int num = base + i;
			if (num == 0)
				continue;
			if (num <= n) {
				res.push_back(num);
				// next digits
				mutliplyDigits(res, n, num * 10);
			}
		}
	}
	vector<int> lexicalOrder(int n) {
		vector<int> res;
		mutliplyDigits(res, n, 0);
		return res;
	}
};