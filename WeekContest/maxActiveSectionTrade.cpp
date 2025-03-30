#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
	int maxActiveSectionsAfterTrade(string s) {
		vector<int> convert;
		int cnt = s[0] == '1' ? 1 : -1;
		char curr_bit = s[0];
		for (int i = 1; i < s.length(); ++i) {

			if (s[i] == '0') {
				if (curr_bit == '0')
					--cnt;
				else {
					convert.push_back(cnt);
					cnt = -1;
				}
			} else {
				if (curr_bit == '1')
					++cnt;
				else {
					convert.push_back(cnt);
					cnt = 1;
				}
			}
			curr_bit = s[i];
		}
		convert.push_back(cnt);
		for (int &cnt : convert) {
			cout << cnt << " ";
		}
		cout << endl;
		int max_trade = 0;
		int max_l = -1;
		int l = -1;
		int curr_trade = 0;
		for (int i = 0; i < convert.size(); ++i) {
			if (convert[i] < 0) {
				if (l < 0) {
					l = i;
					curr_trade += abs(convert[i]);
				} else {
					curr_trade += abs(convert[i]);
					if (curr_trade > max_trade) {
						max_trade = curr_trade;
						max_l = l;

						// reset trade to next
						l = i;
						curr_trade = abs(convert[i]);
					}
				}
			}
		}
		cout << max_trade << endl;
		if (max_trade == 0) {
			int sum = 0;
			for (int &c : convert)
				sum += abs(c);
			return sum;
		}

		if (max_l - 1 >= 0)
			max_trade += convert[max_l - 1];

		if (max_l + 1 < convert.size())
			max_trade += convert[max_l + 1];
		if (max_l + 3 < convert.size())
			max_trade += convert[max_l + 3];
		return max_trade;
	}
};
int main() {
	Solution sol;
	cout << sol.maxActiveSectionsAfterTrade("101");
}