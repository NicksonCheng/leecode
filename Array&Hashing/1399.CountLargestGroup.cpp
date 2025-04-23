
/*
    1. 先去計算有多少digit
    2. create hashtable[9*digit]
    time complexity O(n),

*/
class Solution {
  public:
	int countLargestGroup(int n) {
		vector<int> groups(n + 1, 0);

		for (int i = 1; i <= n; ++i) {
			int sum_digits = 0;
			int num = i;
			while (num > 0) {
				sum_digits += (num % 10);
				num /= 10;
			}
			++groups[sum_digits];
		}
		int count_max_groups = 0;
		int max_group_size = 0;
		for (int i = 0; i < groups.size(); ++i) {
			if (groups[i] == 0)
				continue;
			if (groups[i] > max_group_size) {
				count_max_groups = 1;
				max_group_size = groups[i];
			} else if (groups[i] == max_group_size) {
				++count_max_groups;
			}
		}
		return count_max_groups;
	}
};