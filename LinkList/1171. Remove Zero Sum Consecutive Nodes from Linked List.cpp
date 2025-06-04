// solution
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
    sol.1 prefix sum 相同的index range 就是要刪除的地方

    兩次traverse
    第一次紀錄最後prefix sum出現的地方
    第二次將相同的prefix sum 中間node ignore
    cur->next = prefix_sum[cur]->next;

    edge case: 可能必須從頭開始刪除, 需要dummy node->next = head

*/

class Solution {
  public:
	ListNode *removeZeroSumSublists(ListNode *head) {
		ListNode *cur = head;
		unordered_map<int, ListNode *>
		    prefix_sum; // save prefix sum link list pointer
		int sum = 0;
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		prefix_sum[0] = dummy;

		// record prefix sum last node
		while (cur) {
			sum += cur->val;
			prefix_sum[sum] = cur;
			cur = cur->next;
		}
		// jump ignore same prefix sum
		cur = dummy;
		sum = 0;
		while (cur) {
			sum += cur->val;
			cur->next = prefix_sum[sum]->next;
			cur = cur->next;
		}
		return dummy->next;
	}
};