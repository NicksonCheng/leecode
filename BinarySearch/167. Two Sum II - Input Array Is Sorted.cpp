// proficient
/*
    直接每個num binary search O(nlogn)
*/
class Solution {
  public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> res;
		for (int i = 0; i < numbers.size(); ++i) {
			int n = numbers[i];
			int l = 0;
			int r = numbers.size() - 1;
			int compliment = target - n;
			while (l <= r) {
				int m = (r + l) / 2;
				if (numbers[m] > compliment) {
					r = m - 1;
				} else if (numbers[m] < compliment)
					l = m + 1;
				else {
					// 相同index不允許
					if (m == i) {
						if (numbers[m] == numbers[m + 1]) {
							l = m + 1;
							continue;
						} else if (numbers[m] == numbers[m - 1]) {
							r = m - 1;
							continue;
						} else
							break; // 沒有相同的, 這個是fail case
					}
					res.push_back(i + 1);
					res.push_back(m + 1);
					return res;
				}
			}
		}
		return res;
	}
};

/*
    two pointer, 因為是排序好的, 直接看左右兩邊加總, < target ++left, > target
   --right O(n)
*/
class Solution {
  public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		int l = 0;
		int r = numbers.size() - 1;
		vector<int> res;
		while (l <= r) {
			if (target < numbers[l] + numbers[r])
				--r;
			else if (target > numbers[l] + numbers[r])
				++l;
			else {
				res.push_back(l + 1);
				res.push_back(r + 1);
				break;
			}
		}
		return res;
	}
};