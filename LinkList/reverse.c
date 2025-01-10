#include <stdio.h>
#include <stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode *createListNode(int *arr, int length) {
	struct ListNode *head = malloc(sizeof(struct ListNode));
	struct ListNode *curr = head;
	for (int i = 0; i < length; ++i) {
		curr->val = arr[i];
		if (i + 1 < length) {
			curr->next = malloc(sizeof(struct ListNode));
			curr = curr->next;
		}
	}
	return head;
}
struct ListNode *reverseList(struct ListNode *head) {

	/* keypoint: store ->next pointer and used prev pointer to reverse next*/
	struct ListNode *prev = NULL; // New head of reversed list
	struct ListNode *cur = head;

	while (cur != NULL) {
		struct ListNode *tmp_next = cur->next; // store next pointer
		cur->next = prev;
		prev = cur; // reverse pointer to prev

		cur = tmp_next; // iter to next
	}

	return prev;
}

void printListNode(struct ListNode *head) {
	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}
int main() {
	/*notes:
	  1. must consider first position situation
	  2. ->next in every interation
	  3. used cur to address head value to interate*/
	int arr[] = {3, 2, 5, 1, 4};
	int arr_len = sizeof(arr) / sizeof(arr[0]);
	struct ListNode *head = createListNode(arr, arr_len);
	printListNode(head);
	head = reverseList(head);
	printListNode(head);
	free(head);
}