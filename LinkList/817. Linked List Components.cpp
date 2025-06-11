/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
    nums 轉成set, 然後traverse linklist
    每次set 如果找不到就component + 1(斷點)
    然后不斷while 直到下一個set element 出現
*/
class Solution {
  public:
	int numComponents(ListNode *head, vector<int> &nums) {
		unordered_set<int> num_dict(nums.begin(), nums.end());
		ListNode *cur = head;
		int num_comp = 0;
		while (cur) {
			// find first element in nums
			while (cur && num_dict.count(cur->val) == 0)
				cur = cur->next;

			// find this components length
			int num_element = 0;
			while (cur && num_dict.count(cur->val) > 0) {
				++num_element;
				cur = cur->next;
			}
			if (num_element > 0)
				++num_comp;
		}
		return num_comp;
	}
};