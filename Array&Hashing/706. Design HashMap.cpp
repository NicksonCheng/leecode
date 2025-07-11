struct MyListNode {
	int key;
	int val;
	MyListNode *next;
	MyListNode() : key(0), val(0), next(nullptr) {}
	MyListNode(int key, int val, MyListNode *next)
	    : key(key), val(val), next(next) {}
};
class MyHashMap {
  public:
	int hash_size = 769;
	vector<MyListNode *> hashmap;
	MyHashMap() { hashmap.resize(hash_size, nullptr); }

	void put(int key, int value) {
		int map_key = key % hash_size;
		MyListNode *new_node = new MyListNode(key, value, nullptr);
		MyListNode *head = hashmap[map_key];
		if (!head) {
			hashmap[map_key] = new_node;
			return;
		}
		while (head) {
			if (head->key == key) {
				head->val = value;
				return;
			}
			if (!head->next)
				break;
			head = head->next;
		}
		head->next = new_node;
	}

	int get(int key) {
		int map_key = key % hash_size;
		MyListNode *head = hashmap[map_key];
		while (head) {
			if (head->key == key)
				return head->val;
			head = head->next;
		}
		return -1;
	}

	void remove(int key) {
		int map_key = key % hash_size;
		MyListNode *head = hashmap[map_key];
		if (!head)
			return;
		if (head->key == key) {
			hashmap[map_key] = head->next;
			return;
		}
		MyListNode *cur = head->next;
		MyListNode *prev = head;
		while (cur) {
			if (cur->key == key) {
				prev->next = cur->next;
				delete cur;
				return;
			}
			prev = prev->next;
			cur = cur->next;
		}
	}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */