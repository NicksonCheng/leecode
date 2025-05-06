/*
    1. brutal force: 每個nums2都往後找next greater, O(n^2)
    monotonic stack, num2 從後面traverse回來, nums[i] >
   stack.top()就持續pop直到遇到next great 然後用hashtable紀錄, 如果stack
   empty就是-1

    time complexity O(n), stack push/pop 最多一次
*/
class Solution {
  public:
	vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
		stack<int> s;
		unordered_map<int, int> next_greater;
		vector<int> ans;
		// 後面做回來
		for (int i = nums2.size() - 1; i >= 0; --i) {
			while (!s.empty() && nums2[i] > s.top()) {
				s.pop();
			}
			if (!s.empty()) {
				next_greater[nums2[i]] = s.top();
			} else
				next_greater[nums2[i]] = -1;
			s.push(nums2[i]);
		}
		// push every next greater to ans
		for (int &num : nums1)
			ans.push_back(next_greater[num]);
		return ans;
	}
};