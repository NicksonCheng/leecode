// hint
// 19 minute
//
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*
    1. 因為->random的node還沒建立, 我們必須先用hashmap建立一輪新舊node的對照表
    2. 等node都建立完後再traverse一遍將random的pointer assign 給copy linklist
*/
class Solution {
  public:
	Node *copyRandomList(Node *head) {
		// 先建立玩next 再回來看haskmap裡面去建立random
		unordered_map<Node *, Node *> node_map;
		node_map[nullptr] = nullptr;
		Node *cur = head;
		Node *dummy = new Node(0);
		Node *cur2 = dummy;
		while (cur != nullptr) {
			Node *new_node = new Node(cur->val);
			node_map[cur] = new_node; // 舊的對應新的
			cur2->next = new_node;
			cur2 = cur2->next;
			cur = cur->next;
		}
		cur = head;
		cur2 = dummy->next;
		while (cur != nullptr) {
			cur2->random = node_map[cur->random];
			cur = cur->next;
			cur2 = cur2->next;
		}

		return dummy->next;
	}
};
