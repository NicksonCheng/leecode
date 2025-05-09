// solution
/*
    要紀錄每個process的冷卻時間, 然後丟進max_heap
    每次都拿剩餘做多的process來用, 但時如果還在冷卻就不行

    每次heap拿出來如果process還沒用完,
   就把它下一次可以取用的時間push到queue裡面(front一定是最小的不需排序用普通queue即可)

    time complexity O(m * log P), m = number of tasks, P = 不同task數量(A~Z)
   為常數倍, 所以totoal time complexity O(m)
*/
class Solution {
  public:
	int leastInterval(vector<char> &tasks, int n) {
		int cur_t = 0;
		unordered_map<char, int> p_count;
		queue<pair<int, pair<int, char>>> cooldown;
		priority_queue<pair<int, char>> processes;
		for (char &p : tasks)
			++p_count[p];
		for (auto &pc : p_count)
			processes.push({pc.second, pc.first});

		while (!processes.empty() || !cooldown.empty()) {
			// 先查看冷卻時間是否結束, 如果結束就push回heap裡面
			if (!cooldown.empty() && cooldown.front().first <= cur_t) {
				processes.push(cooldown.front().second);
				cooldown.pop();
			}
			// 如果只剩cooldown還是得等他們跑完
			if (processes.empty()) {
				// optimize: 直接跳到下一個cooldown時間
				cur_t = cooldown.front().first;
				continue;
			}
			pair<int, char> p = processes.top();
			int count = p.first;
			int p_name = p.second;
			// 要到 cur_t + n + 1才能用
			if (count - 1 > 0)
				cooldown.push({cur_t + n + 1, {count - 1, p_name}});

			processes.pop();
			++cur_t;
		}
		return cur_t;
	}
};