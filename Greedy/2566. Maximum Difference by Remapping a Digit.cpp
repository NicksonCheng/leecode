// proficient
/*
    greedy 找第一個不是9 or 0 的 digit, 改成 9 跟 0

    O(n)
*/
class Solution {
  public:
	int minMaxDifference(int num) {
		stack<int> digit;
		while (num > 0) {
			digit.push(num % 10);
			num /= 10;
		}
		int max_remap = -1;
		int min_remap = -1;
		int max = 0;
		int min = 0;
		while (!digit.empty()) {
			// cout << digit.top() << endl;
			if (digit.top() < 9 && max_remap == -1) {
				max_remap = digit.top();
			}
			if (digit.top() > 0 && min_remap == -1)
				min_remap = digit.top();

			if (digit.top() == max_remap)
				max += 9 * pow(10, digit.size() - 1);
			else
				max += digit.top() * pow(10, digit.size() - 1);

			if (min_remap != -1 && digit.top() != min_remap)
				min += digit.top() * pow(10, digit.size() - 1);
			digit.pop();
		}
		return max - min;
	}
};