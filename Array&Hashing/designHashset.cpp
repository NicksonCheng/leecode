/*
    vector:
        add O(n)-> need to remove duplicated
        remove O(n)
        contains O(n)

*/
class MyHashSet {
  public:
	vector<int> custom_set;
	vector<int>::iterator iter;
	MyHashSet() {}

	void add(int key) {
		iter = find(custom_set.begin(), custom_set.end(), key);
		if (iter == custom_set.end())
			custom_set.push_back(key);
		else {
			custom_set.erase(iter);
			custom_set.push_back(key);
		}
	}

	void remove(int key) {
		iter = find(custom_set.begin(), custom_set.end(), key);
		if (iter != custom_set.end())
			custom_set.erase(iter);
	}

	bool contains(int key) {
		iter = find(custom_set.begin(), custom_set.end(), key);
		return iter != custom_set.end();
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */