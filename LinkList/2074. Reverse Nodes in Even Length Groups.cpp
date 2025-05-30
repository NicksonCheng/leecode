// proficient
// 25 minute
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
    紀錄上一個odd 的 end
    然後even reverse, 最後將odd end 接到even 的 begin, 然後even 的end
   接到下一個odd的begin

    注意點: 有可能最後一個group size不夠變成 odd->even->odd->even->even,
   要注意這個case
*/
class Solution {
  public:
	ListNode *reverseEvenLengthGroups(ListNode *head) {
		ListNode *cur = head;
		// 可能end 是 even, 要先確認total
		int total_nodes = 0;
		while (cur) {
			++total_nodes;
			cur = cur->next;
		}
		int group_size = 1;
		cur = head;
		ListNode *last_odd_end = nullptr;
		while (cur != nullptr) {
			int i = 0;
			// cout << total_nodes << " " << group_size << endl;
			if (total_nodes < group_size)
				group_size = total_nodes;
			if (group_size % 2 != 0) {
				// move to even begin
				while (cur && i < group_size) {
					last_odd_end = cur;
					cur = cur->next;
					++i;
				}

			} else {
				// reverse even group
				ListNode *prev = nullptr;
				ListNode *even_begin = cur;
				while (cur && i < group_size) {
					ListNode *tmp = cur->next;
					cur->next = prev;
					prev = cur;
					cur = tmp;
					++i;
				}
				last_odd_end->next = prev; // last odd end to reversed even head
				last_odd_end = even_begin; // 避免最後出現even
				even_begin->next = cur;    // reversed even end to next odd head
			}
			total_nodes -= (group_size++);
		}
		return head;
	}
};