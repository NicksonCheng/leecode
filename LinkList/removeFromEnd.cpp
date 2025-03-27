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
    1. 先去算有多少node
    2. node_length - n = target remove index
    3. 去找remove index 然後remove他(prev->next = cur->next)
*/
class Solution {
  public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode *cur = head;

		int node_len = 0;
		while (cur != nullptr) {
			++node_len;
			cur = cur->next;
		}
		cur = head;
		ListNode *prev = nullptr;
		int remove_idx = node_len - n;
		int i = 0;
		if (remove_idx == i)
			return head->next;
		while (cur != nullptr) {
			if (i == remove_idx) {
				prev->next = cur->next;
				return head;
			}
			prev = cur;
			cur = cur->next;
			++i;
		}
	}
};
