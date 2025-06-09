// proficient
/*
    sol.1 Sorting, Greedy 先從最重的開始載, 然後從最輕的另一邊找誰可以配對
    認真看題目, 規定只能載兩人

    1 2 2 3
*/
class Solution {
  public:
	int numRescueBoats(vector<int> &people, int limit) {
		int n = people.size();
		sort(people.begin(), people.end());
		int l = 0;
		int r = n - 1;
		int res = 0;
		while (l <= r) {
			if (people[r] + people[l] <= limit) {
				++l;
			}
			++res;
			--r;
		}
		return res;
	}
};