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

/* 5/1 pratices */
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
    先找到k個node, reverse他們, 並且group_cur先接到next_group_cur,
    如果下次group不滿足k個就結束
    如果還有就要把上一個group_cur接到這次k_th node
*/
class Solution {
  public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *prev_end = dummy;
		while (true) {
			// find kth node
			ListNode *group_start = prev_end->next;
			ListNode *kth = findKthNode(group_start, k);

			// not enough, finish
			if (!kth)
				break;
			ListNode *next_group_start = kth->next;
			// reverse current group
			ListNode *prev =
			    kth->next; // temporarily connection to next group start
			ListNode *cur = group_start;

			while (cur != next_group_start) {
				ListNode *tmp = cur->next;
				cur->next = prev;
				prev = cur;
				cur = tmp;
			}

			// 將上一組（或 dummy 節點）連接到這一組反轉後的頭節點（kth）
			prev_end->next = kth;

			// 將 prev_end 更新為這一組反轉後的最後一個節點（原本的
			// group_start）， 以便在下一輪反轉時能正確接上下一組
			prev_end = group_start;
		}
		return dummy->next;
	}
	ListNode *findKthNode(ListNode *cur, int k) {
		int count = 0;
		ListNode *kth = nullptr;
		while (cur) {
			++count;
			if (count == k) {
				kth = cur;
				break;
			}
			cur = cur->next;
		}
		return kth;
	}
};