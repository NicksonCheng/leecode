/*

    兩個index, i 紀錄目前要增加的次數, j(s.back()) 去看目前要增加1 or 2
*/
class Solution {
  public:
	int magicalString(int n) {
		string s = "122";
		int i = 2; // count the number of times to add 1 or 2

		while (s.length() < n) {
			char next_num = s.back() == '1' ? '2' : '1';
			int count = s[i] - '0';

			for (int k = 0; k < count; ++k)
				s += next_num;
			++i; // next need to add
		}
		int res = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1')
				++res;
		}
		return res;
	}
};