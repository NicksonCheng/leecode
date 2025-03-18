/*key point
 *1. the list has been reverse, just add it directly
 *2. carefully used carry to sum up
 *3. used dummy node at first, and return dummy->next in the end
 */
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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *dummy = (ListNode *)new ListNode();
		ListNode *cur = dummy;
		int carry = 0;
		while (l1 || l2 || carry > 0) {
			/* code */
			int v1 = l1 ? l1->val : 0;
			int v2 = l2 ? l2->val : 0;
			int sum = v1 + v2 + carry;
			carry = sum / 10;
			sum = sum % 10;
			ListNode *new_node = (ListNode *)new ListNode();
			cur->next = new_node;
			cur->next->val = sum;

			cur = cur->next;
			l1 = l1 ? l1->next : nullptr;
			l2 = l2 ? l2->next : nullptr;
		}
		ListNode *res = dummy->next;
		cout << "successful" << endl;
		return res;
	}
};

int main() {
	Solution s;

	int arr1[3] = {5, 7, 8};
	int arr2[3] = {8, 3, 6};
	ListNode *list1 = s.createList(arr1, 3);
	ListNode *list2 = s.createList(arr2, 3);
	ListNode *res = s.addTwoNumbers(list1, list2);
	while (res) {
		/* code */
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;

	return 0;
}