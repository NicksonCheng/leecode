// hint
/*
    1. 暴力法直接vector<pair<int,int>> 去尋找值

    2.
    hashtable去存key-list_iter
    list(double link-list) 去執行insert/erase
*/
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

class LRUCache {
  public:
	int cache_n = 0;
	list<int> cache_container;
	unordered_map<int, pair<int, list<int>::iterator>> cache_table;
	LRUCache(int capacity) { cache_n = capacity; }

	int get(int key) {
		if (cache_table.find(key) == cache_table.end())
			return -1;
		else {
			update_LRU(key, cache_table[key].first);
			return cache_table[key].first;
		}
	}

	void put(int key, int value) {
		// new key value
		if (cache_table.find(key) == cache_table.end()) {

			cache_container.push_back(key);
			cache_table[key] = {value, prev(cache_container.end())};

			if (cache_container.size() > cache_n) {
				int lru_key = cache_container.front();
				cache_table.erase(lru_key);
				cache_container.pop_front();
			}

		}
		// update key value
		else {
			update_LRU(key, value);
		}
	}
	void update_LRU(int key, int value) {
		list<int>::iterator iter = cache_table[key].second;
		// update LRU
		cache_container.erase(iter);
		cache_container.push_back(key);

		// update hashtable iter
		cache_table[key] = {value, prev(cache_container.end())};
	}
};
