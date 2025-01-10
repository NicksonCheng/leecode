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
void printListNode(struct ListNode *head) {
	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}
struct ListNode *insertNode(struct ListNode *head, int value, int position) {
	int cnt = 0;
	struct ListNode *cur = head;
	if (cnt == position) {
		struct ListNode *tmp = malloc(sizeof(struct ListNode));
		tmp->val = value;
		tmp->next = cur;
		return tmp;
	}
	while (cur) {
		/* code */
		if ((cnt + 1) == position) {
			struct ListNode *tmp = malloc(sizeof(struct ListNode));
			tmp->val = value;
			tmp->next = cur->next;
			cur->next = tmp;
			return head;
		}
		cur = cur->next;
		++cnt;
	}
	printf("wrong position !\n");

	return head;
}
struct ListNode *removeNode(struct ListNode *head, int position) {
	if (position == 0) {
		struct ListNode *tmp = head->next;
		free(head);
		return tmp;
	}
	struct ListNode *cur = head;
	int cnt = 0;
	while (cur) {
		if (cnt + 1 == position) {
			struct ListNode *tmp = cur->next;
			cur->next = tmp->next;
			free(tmp);
			return head;
		}
		cur = cur->next;
		++cnt;
	}
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
	head = insertNode(head, 10, 3);
	printListNode(head);
	head = removeNode(head, 4);
	printListNode(head);
	free(head);
}