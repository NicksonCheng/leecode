// hint
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode* next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode* next) : val(x), next(next) {}
 * };
 */

/*
    想法正確, 作法錯誤,
    1. 先跑到要reverse的地點
    2. 紀錄等等要接的點prev, cur
    3. reverse,然後跑到右邊要接的點
    4. 接起來
    5. 注意left == 1的情況, nullptr會造成segmentation fault
*/
class Solution {
  public:
	ListNode *reverseBetween(ListNode *head, int left, int right) {
		if (!head || left == right)
			return head;

		// Create a dummy node to handle edge cases where left == 1
		ListNode *dummy = new ListNode(0, head);
		ListNode *prev = dummy;
		ListNode *cur = head;

		// Move to the node just before the reversing part
		for (int i = 1; i < left; ++i) {
			prev = cur;
			cur = cur->next;
		}

		// Markers for the reversing part
		ListNode *con = prev; // Connection to the reversed sublist
		ListNode *tail = cur; // The end of the reversed sublist

		// Reverse the sublist from left to right
		ListNode *next = nullptr;
		for (int i = left; i <= right; ++i) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}

		// Adjust connections
		con->next = prev;
		tail->next = cur;

		// Return the new head
		return dummy->next;
	}
};
