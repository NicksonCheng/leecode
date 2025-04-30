// solution
/* 難到靠杯*/
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
2->1  3->4->5

2->1  4->3  5

*/
class Solution {
  public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *prev_group_end = dummy;
		while (true) {
			ListNode *group_start =
			    prev_group_end->next; // pointer to current group start
			ListNode *k_th = findKthNode(group_start, k);
			// 後續node不足k個, 不需要處理
			if (!k_th)
				break;
			ListNode *next_group_start =
			    k_th->next; // pointer to next group start

			/* reverse group */
			ListNode *prev =
			    next_group_start; /* 先暫時黏到下一個group start,
			                        如果下一個group不滿足ｋ個就不處理,
			                        不然就會會在(handle different
			                       group connection)處理
			                      */
			ListNode *cur = group_start;
			while (cur != next_group_start) {
				ListNode *tmp = cur->next;
				cur->next = prev;
				prev = cur;
				cur = tmp;
			}
			/**/

			/* handle different group connection */
			// set prev_end next to kth
			prev_group_end->next = k_th;

			// update prev_group_end to current group start
			prev_group_end = group_start;
			/**/
		}
		return dummy->next;
	}
	ListNode *findKthNode(ListNode *start, int k) {
		int count = 0;
		ListNode *k_th = nullptr;
		while (start != nullptr) {
			++count;
			if (count == k) {
				k_th = start;
				break;
			}
			start = start->next;
		}
		return k_th;
	}
};