/* Link List implementation queue*/
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {};

// };

/*
enQueue: O(1)
deQueue: O(n)
Front: O(n) -> O(1) 多一個tail pointer
Rear: O(1)
isEmpty: O(1)
isFull: O(n) -> 多一個counter variable
*/
class MyCircularQueue {
  public:
	int k;
	ListNode *head;
	ListNode *tail;
	int count = 0;
	MyCircularQueue(int k) {
		this->k = k;
		head = nullptr;
		tail = nullptr;
	}

	bool enQueue(int value) {
		if (isFull())
			return false;
		ListNode *new_node = new ListNode(value);

		if (tail) {
			tail->next = new_node;
			tail = new_node;
		} else {
			head = new_node;
			tail = head;
		}
		++count;
		return true;
	}

	bool deQueue() {
		if (!tail)
			return false;
		else {
			// deleted from head

			ListNode *tmp = head;
			head = head->next;
			delete tmp;
			--count;
			if (count == 0)
				tail = nullptr;
			return true;
		}
	}

	int Front() {
		if (!head)
			return -1;
		else
			return head->val;
	}

	int Rear() {
		if (!tail)
			return -1;
		else
			return tail->val;
	}

	bool isEmpty() { return head == nullptr; }

	bool isFull() { return count == k; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */