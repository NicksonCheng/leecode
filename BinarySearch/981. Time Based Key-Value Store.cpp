/*
    hashmap<string,vector<int> time stamp>
    因為是ascending, 所以用binary search去尋找 upperbound, return upper bound -
   1 index
*/
class TimeMap {
  public:
	unordered_map<string, vector<pair<int, string>>> m;
	TimeMap() {}

	void set(string key, string value, int timestamp) {
		m[key].push_back({timestamp, value});
	}

	string get(string key, int timestamp) {
		if (m.find(key) == m.end())
			return "";

		int l = 0;
		int r = m[key].size();

		// 尋找upper bond
		while (l < r) {
			int mid = (l + r) / 2;

			if (m[key][mid].first > timestamp)
				r = mid;
			else
				l = mid + 1;
		}
		if (l == 0)
			return "";
		return m[key][l - 1].second;
	}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */