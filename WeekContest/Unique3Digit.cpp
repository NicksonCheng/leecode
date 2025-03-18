#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
  public:
	int totalNumbers(vector<int> &digits) {
		vector<int> even_digits;
		unordered_map<int, int> digits_cnt;

		for (int i = 0; i < digits.size(); ++i) {
			++digits_cnt[digits[i]];
			if (digits[i] % 2 == 0)
				even_digits.push_back(digits[i]);
		}
		unordered_set<int> number_set;
		for (int i = 0; i < digits.size(); ++i) {
			for (int j = 0; j < digits.size(); ++j) {
				for (int k = 0; k < even_digits.size(); ++k) {
					if (i != j && j != k && i != k && digits[i] != 0) {
						if (digits[i] == digits[j] && digits[j] == digits[k] &&
						    digits_cnt[digits[i]] < 3) {
							continue;
						}
						int number =
						    digits[i] * 100 + digits[j] * 10 + even_digits[k];
						number_set.insert(number);
					}
				}
			}
		}
		for (auto &s : number_set)
			cout << s << endl;
		return number_set.size();
	}
};
int main() {
	Solution sol;
	vector<int> digits = {8, 1, 8};
	cout << sol.totalNumbers(digits) << endl;
}