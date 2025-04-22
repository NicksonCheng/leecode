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
    1. reverse linklist, 再two pointer兩個linklist去check Palindrome, time
   complexityO(n), space complexity O(n)

    2. 不用另外create linklist, 先確認中間的node, 然後從中間的node開始reverse,
        然後再確認palindrome, time complexity O(n), space O(1)
*/
class Solution {
  public:
	bool isPalindrome(ListNode *head) {
		ListNode *cur = head;
		ListNode *tail = nullptr;
		int count = 0;
		while (cur != nullptr) {
			ListNode *new_node = new ListNode(cur->val);
			new_node->next = tail;
			tail = new_node;
			cur = cur->next;
			++count;
		}

		count /= 2;
		while (count > 0) {
			if (head->val != tail->val)
				return false;
			head = head->next;
			tail = tail->next;
			--count;
		}
		return true;
	}
};

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
class Solution {
  public:
	bool isPalindrome(ListNode *head) {
		int count = 0;
		ListNode *cur = head;

		while (cur != nullptr) {
			cur = cur->next;
			++count;
		}

		// reverse start node
		int m = count / 2;
		cur = head;

		for (int i = 0; i < m; ++i) {
			cur = cur->next;
		}
		// reverse last half link list
		ListNode *prev = nullptr;
		while (cur != nullptr) {
			ListNode *tmp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = tmp;
		}

		while (m > 0 && prev != nullptr && head != nullptr) {
			if (prev->val != head->val)
				return false;
			prev = prev->next;
			head = head->next;
			--m;
		}
		return true;
	}
};