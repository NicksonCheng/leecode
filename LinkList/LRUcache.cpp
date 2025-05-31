/*
    要一個container去存每個key的timestamp,
   並且在更新timestamp的時候可以隨時erase/insert, double link list 為最佳

    sol.1
    hashtable存每個key 的 list iterator(pointer), 可以順便存key, 省下list find
   O(n) 時間

    new key, list.push_front, update key, list erase original, insert to first

    list size超出capacity, erase list.back

    time complexity()

    get(): O(1)
    put(): O(1)

    space complexity: O(k)

*/
class LRUCache {
  public:
	unordered_map<int, pair<int, list<int>::iterator>> cache_table;
	list<int> cache_list;
	int capacity;
	LRUCache(int capacity) { this->capacity = capacity; }

	int get(int key) {
		if (cache_table.count(key) == 0)
			return -1;
		else {
			// 要先update timestamp
			cache_list.erase(cache_table[key].second);
			cache_list.push_front(key);
			cache_table[key].second = cache_list.begin();
			return cache_table[key].first;
		}
	}

	void put(int key, int value) {
		if (cache_table.count(key) == 0) {
			// new key,value
			cache_list.push_front(key);
			cache_table[key] = {value, cache_list.begin()};
		} else {
			// update key,value and time stamp
			cache_list.erase(cache_table[key].second);
			cache_list.push_front(key);
			cache_table[key] = {value, cache_list.begin()};
		}
		// check is out of capacity
		if (cache_list.size() > capacity) {
			int remove_key = cache_list.back();
			cache_list.pop_back();
			cache_table.erase(remove_key);
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */