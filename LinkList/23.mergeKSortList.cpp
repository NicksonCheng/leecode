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
    1. 在每個link list item移動的同時要改變他的next pointer, O(n * k), space
   O(1)
    2. heap, 因為每個list已經排序好, 真正要重排的是vector k O(logk), 有n個list,
   time O(nlogk)

   3. 暴力法, 直接存到新的array 再重新sort, time complexity O(nlogn)

   4. divide and conquar, 每層merge兩個list, 總共log(k)層, 每次merge n個,
   O(nlogk)
*/
class Solution {
  public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode *dummy = new ListNode(0);
		ListNode *cur = dummy;
		while (true) {
			// check  if every linklist item to the end
			bool end = true;
			int min_val = INT_MAX;
			int min_idx = 0;
			for (int i = 0; i < lists.size(); ++i) {
				if (lists[i] == nullptr)
					continue;
				end = false;
				if (lists[i]->val < min_val) {
					min_idx = i;
					min_val = lists[i]->val;
				}
			}
			if (end)
				break;
			cur->next = lists[min_idx];
			lists[min_idx] = lists[min_idx]->next;
			cur = cur->next;
		}
		return dummy->next;
	}
};

/* heap解法*/

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
typedef struct Compared {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		return a.second > b.second;
	}
} Compared;
class Solution {
  public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode *dummy = new ListNode(0);
		ListNode *cur = dummy;
		priority_queue<pair<int, int>, vector<pair<int, int>>, Compared>
		    min_heap;

		for (int i = 0; i < lists.size(); ++i) {
			if (lists[i] == nullptr)
				continue;
			min_heap.push({i, lists[i]->val});
		}
		while (!min_heap.empty()) {
			int min_idx = min_heap.top().first;
			cur->next = lists[min_idx];
			cur = cur->next;
			lists[min_idx] = lists[min_idx]->next;
			min_heap.pop();

			// push next list[i] item
			if (lists[min_idx] != nullptr)
				min_heap.push({min_idx, lists[min_idx]->val});
		}

		return dummy->next;
	}
};