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
	ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {

		struct ListNode *head = new ListNode();
		struct ListNode *cur = head;
		while (list1 && list2) {
			cout << list1->val << " " << list2->val << endl;
			if (list1->val < list2->val) {
				cur->next = list1;
				list1 = list1->next;
				cur = cur->next;
			} else {
				cur->next = list2;
				list2 = list2->next;
				cur = cur->next;
			}
		}
		while (list1) {
			/* code */
			cur->next = list1;
			list1 = list1->next;
			cur = cur->next;
		}
		while (list2) {
			/* code */
			cur->next = list2;
			list2 = list2->next;
			cur = cur->next;
		}

		cout << "successful" << endl;
		return head->next;
	}
};
int main() {
	Solution sol;
	struct ListNode *list1 = new ListNode();
	struct ListNode *list2 = new ListNode();
	struct ListNode *tmp1 = list1;
	struct ListNode *tmp2 = list2;
	vector<int> v1 = {1, 2, 4};
	vector<int> v2 = {1, 2, 5};
	for (int i = 0; i < v1.size(); ++i) {
		tmp1->val = v1[i];
		tmp2->val = v2[i];
		if (i + 1 < v1.size()) {
			struct ListNode *next1 = new ListNode();
			struct ListNode *next2 = new ListNode();
			tmp1->next = next1;
			tmp2->next = next2;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}

	struct ListNode *merge_nodes = sol.mergeTwoLists(list1, list2);
	while (merge_nodes) {
		/* code */
		cout << merge_nodes->val << " ";
		merge_nodes = merge_nodes->next;
	}
	cout << endl;
	return 0;
}