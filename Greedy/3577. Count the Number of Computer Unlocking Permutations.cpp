// solution
/*
    先看computer 0 能不能解開所有, 可以的話我們可以用任何順序去
    unlock, 答案是 (n - 1)!

    如果不行就是0
*/
#include <iostream>
#include <queue>
using namespace std;
class Solution {
  public:
	int countPermutations(vector<int> &complexity) {
		int pc = complexity[0];
		int n = complexity.size();
		long long res = 1;
		int modolo = 1e9 + 7;
		for (int i = 1; i < n; ++i) {
			if (complexity[i] <= pc)
				return 0;
			else
				res = (res * i) % modolo;
		}
		return res;
	}
};