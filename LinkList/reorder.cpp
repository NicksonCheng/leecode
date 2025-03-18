#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  public:
	ListNode *createList(int *arr, int arr_len) {
		ListNode *head = (ListNode *)new ListNode();
		ListNode *cur = head;
		for (int i = 0; i < arr_len; ++i) {
			if (i != arr_len - 1) {
				ListNode *node = (ListNode *)new ListNode();
				cur->next = node;
			}
			cur->val = arr[i];

			cur = cur->next;
		}
		return head;
	}
	void reorderList(ListNode *head) {

		// find middle of linkist(slow, fast)

		// reverse second half list

		// merge two link list
		ListNode *fast = head->next;
		ListNode *slow = head;

		while (fast && fast->next) {
			/* code */
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode *second = slow->next;
		ListNode *prev = slow->next = nullptr; // key point, because we need to
		                                       // truncate second half(nullptr)
		while (second) {
			/* code */
			ListNode *tmp = second->next;
			second->next = prev;
			prev = second;
			second = tmp;
		}
		second = prev;
		ListNode *first = head;
		while (second) {
			/* code */
			ListNode *tmp1 = first->next;
			ListNode *tmp2 = second->next;

			first->next = second;
			second->next = tmp1;
			first = tmp1;
			second = tmp2;
		}
	}
};

int main() {
	Solution s;

	int arr[4] = {2, 4, 6, 8};
	ListNode *head = s.createList(arr, 4);
	s.reorderList(head);
	return 0;
}