// proficient
/*1. hashtable 儲存目前這個digits sum(max heap存), 然後每個digit再找最大
的兩個相加看誰最大 time: O(n* max_digits), space: O(n)

2.*/
class Solution {
  public:
	int maximumSum(vector<int> &nums) {
		unordered_map<int, priority_queue<int>> same_digits_sum;
		int max = -1;
		for (int i = 0; i < nums.size(); ++i) {
			int digits_sum = 0;
			int num = nums[i];
			while (num > 0) {
				digits_sum += (num % 10);
				num /= 10;
			}
			same_digits_sum[digits_sum].push(nums[i]);
		}
		for (auto &numbers : same_digits_sum) {

			priority_queue<int> max_heap = numbers.second;
			// cout<< numbers.first<<" "<< max_heap.size()<< endl;
			if (max_heap.size() < 2)
				continue;

			int n1 = max_heap.top();
			max_heap.pop();
			int n2 = max_heap.top();
			max_heap.pop();
			int sum = n1 + n2;
			// cout<<sum<<endl;
			if (sum > max)
				max = sum;
		}
		return max;
	}
};