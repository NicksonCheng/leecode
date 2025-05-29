/*
    g1, g2 各自BFS, g1 找even, g2 找odd(因為connect g1 會+1變even )
    time : O(n^2 + m^2) TLE

    sol 2. 只需要BFS 一次就好, 我們只關心even/odd, 那就只要一個node 0 BFS,
   然後其他node 根據跟0的距離是even/odd判斷even/odd數量即可, path = even, node i
   = node 0 path = odd,  node i = node 0 even/odd 反過來

    time: O(n + m)
*/
class Solution {
  public:
	vector<int> node_level; // 用來記錄 graph 1 每個node level
	pair<int, int> countTargets(vector<vector<int>> &g, int type) {
		vector<bool> visit(g.size(), false);
		queue<int> q;
		q.push(0);
		int level = 0;
		int num_even = 0;
		int num_odd = 0;
		while (!q.empty()) {
			int size = q.size();
			level % 2 == 0 ? num_even += size : num_odd += size;
			for (int i = 0; i < size; ++i) {
				int node = q.front();
				q.pop();
				visit[node] = true;
				if (type == 1)
					node_level[node] = level;
				for (int &nei : g[node]) {
					if (!visit[nei])
						q.push(nei);
				}
			}
			++level;
		}
		return {num_even, num_odd};
	}
	vector<int> maxTargetNodes(vector<vector<int>> &edges1,
	                           vector<vector<int>> &edges2) {
		int n = edges1.size();
		int m = edges2.size();
		vector<vector<int>> g1(n + 1);
		vector<vector<int>> g2(m + 1);
		node_level.resize(n + 1, 0);
		vector<int> ans(n + 1);
		for (auto &e : edges1) {
			g1[e[0]].push_back(e[1]);
			g1[e[1]].push_back(e[0]);
		}

		for (auto &e : edges2) {
			g2[e[0]].push_back(e[1]);
			g2[e[1]].push_back(e[0]);
		}

		auto [even_1, odd_1] = countTargets(g1, 1);
		auto [even_2, odd_2] = countTargets(g2, 2);
		int max_odd_2 = max(even_2, odd_2); // find max odd from graph 2

		for (int i = 0; i < ans.size(); ++i) {
			int target_node = node_level[i] % 2 == 0 ? even_1 : odd_1;
			ans[i] = max_odd_2 + target_node;
		}
		return ans;
	}
};