/*
    sol.1: brutal force 從leftmost 不斷找符合adj alphet 的char, 找到後刪除,
   再重頭reaptly找, time O(n^3)

    sol 2. two pointer, 先找到leftmost adj後, left, right去不斷loop
   查看是否符合條件, 直到string empty or 不符合條件, 這時就把(left,
   right)的substring刪除return

    注意: 如果left提早<0, 那就要移動到目前right + 1 的部分
    search O(n)

    deleted O(n)

*/
class Solution {
  public:
	string resultingString(string s) {
		int n = s.length();
		int i = 0;
		while (i < n - 1) {
			// leftmost adj consecutive
			if (abs(s[i] - s[i + 1]) == 1 || abs(s[i] - s[i + 1]) == 25) {
				int l = i;
				int r = i + 1;

				while (l >= 0 && r < n &&
				       (abs(s[l] - s[r]) == 1 || abs(s[l] - s[r]) == 25)) {
					--l;
					++r;
				}

				// deleted [l,r] substring
				// cout << l << " " <<  r << endl;
				s.erase(l + 1, r - l - 1);
				i = 0;
				n = s.length();
				if (s.empty())
					break;
			} else {
				++i;
			}
		}
		return s;
	}
};
©leetcode