#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int key;
	int value;
	struct Node *next;
} Node;
typedef struct HashTable {
	int size;
	Node **table; /* array of linklist, here is hashtable,
	              this structure is hashtable information(contain size)*/
} HashTable;
int hash(int key, int size) {
	key = abs(key);
	return key % size;
}
HashTable *craeteHashTable(int size) {
	HashTable *hashtable = (HashTable *)malloc(sizeof(HashTable));
	hashtable->size = size;
	hashtable->table = (Node **)malloc(sizeof(Node *) * size);
	for (int i = 0; i < size; ++i) {
		hashtable->table[i] = NULL;
	}
	return hashtable;
}
int search(HashTable *hashtable, int key) {
	int hash_idx = hash(key, hashtable->size);

	Node *curr_node = hashtable->table[hash_idx];
	while (curr_node != NULL) {
		/* code */
		if (curr_node->key == key) {
			return curr_node->value;
		}
		curr_node = curr_node->next;
	}
	return -1;
}

void insert(HashTable *hashtable, int key, int value) {
	int hash_idx = hash(key, hashtable->size);
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->key = key;
	new_node->value = value;
	new_node->next = hashtable->table[hash_idx];
	hashtable->table[hash_idx] = new_node;
}
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
	HashTable *hastable = craeteHashTable(numsSize * 2);
	for (int i = 0; i < numsSize; ++i) {
		int compliment = target - nums[i];
		int res_idx = search(hastable, compliment);
		if (res_idx != -1) {
			int *pair = (int *)malloc(sizeof(int) * 2);
			pair[0] = res_idx;
			pair[1] = i;
			*returnSize = 2;
			return pair;
		}
		insert(hastable, nums[i], i);
	}
	*returnSize = 0;
	return malloc(sizeof(int) * 0);
}
int main() {
	int nums[] = {2, 17, 7, 15};
	int target = 9;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int returnSize;
	int *result = twoSum(nums, numsSize, target, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("result[%d] = %d\n", i, result[i]);
	}
	return 0;
}