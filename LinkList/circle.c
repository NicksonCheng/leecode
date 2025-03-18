
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode *createListNode(int *arr, int length, int target_idx) {
	struct ListNode *head = malloc(sizeof(struct ListNode));
	struct ListNode *curr = head;
	struct ListNode *target = NULL;
	for (int i = 0; i < length; ++i) {
		curr->val = arr[i];
		if (i == target_idx) {
			target = curr;
		}
		if (i + 1 < length) {
			curr->next = malloc(sizeof(struct ListNode));
			curr = curr->next;
		}
	}
	// create circle
	curr->next = target;
	return head;
}
bool hasCycle(struct ListNode *head) {
	if (head == NULL) {
		return false;
	}
	struct ListNode *curr1 = head->next; // fast
	struct ListNode *curr2 = head;       // slow
	while (curr1 != NULL && curr2 != NULL && curr1->next) {
		/* code */

		if (curr1 != curr2) {
			curr1 = curr1->next->next;
			curr2 = curr2->next;
		} else
			return true;
	}
	return false;
}
int main(int argc, char *argv[]) {
	int arr[5] = {3, 2, -1, 5, 6};
	struct ListNode *head = createListNode(arr, 1, -1);
	if (hasCycle(head))
		printf("Has circle");
	else
		printf("No circle");

	return 0;
}
