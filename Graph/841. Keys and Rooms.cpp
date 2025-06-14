/*
    BFS, 每次用拿到的key 打開room, 並記錄打開的room count, 如果count ==
   rooms.size(), 代表全部打開
*/
class Solution {
  public:
	bool canVisitAllRooms(vector<vector<int>> &rooms) {
		queue<int> q;
		unordered_set<int> opened; // 可能會有重複key
		opened.insert(0);
		for (int &key : rooms[0])
			q.push(key);

		while (!q.empty()) {
			int cur_key = q.front();
			if (opened.count(cur_key) > 0) {
				// already open
				q.pop();
				continue;
			}
			opened.insert(cur_key);
			for (int &next_key : rooms[cur_key]) {
				q.push(next_key);
			}
		}
		return opened.size() == rooms.size();
	}
};