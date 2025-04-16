
// hint
/*
    每個couse都去走一遍DFS, 檢查看看會不會出現重複element(hashset), 如果有return
   false;

    必須增加visit避免重複訪問
*/
class Solution {
  public:
	unordered_map<int, vector<int>> neis_map;
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {

		// create graph
		for (int i = 0; i < prerequisites.size(); ++i) {
			int node_id = prerequisites[i][0];
			int nei = prerequisites[i][1];
			neis_map[node_id].push_back(nei);
		}
		// dfs all nodes;
		bool can_schedule = true;
		vector<bool> visit(numCourses, false);
		for (auto &nodes : neis_map) {
			int node = nodes.first;
			vector<int> neis = nodes.second;
			unordered_set<int> topology; // check cycle in graph
			can_schedule = can_schedule && dfs(node, neis, topology, visit);
		}
		return can_schedule;
	}
	bool dfs(int node, vector<int> &neis, unordered_set<int> &topology,
	         vector<bool> &visit) {
		if (visit[node])
			return true;
		// graph contain cycle
		if (topology.find(node) != topology.end()) {
			return false;
		}

		topology.insert(node);
		for (int i = 0; i < neis.size(); ++i) {
			int next_node = neis[i];
			if (!dfs(next_node, neis_map[next_node], topology, visit))
				return false;
		}
		visit[node] = true;
		return true;
	}
};

/*
    BFS 拓撲排序（Kahn's Algorithm）
    先去計算每個node的in_degree, 然後從0-indegree的node開始刪除
    並且刪除跟這個node有關的in_degree, 再將in-degree變0的node加入queue重複做
    如果最後能夠刪除所有node,代表graph沒有cycle
*/
class Solution {
  public:
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
		vector<vector<int>> graph(numCourses);
		vector<int> in_degree(numCourses, 0);
		queue<int> deleted_nodes;
		for (auto &pre : prerequisites) {
			int course = pre[0];
			int prereq = pre[1];
			graph[prereq].push_back(course);
			in_degree[course]++;
		}

		for (int i = 0; i < in_degree.size(); ++i) {
			if (in_degree[i] == 0)
				deleted_nodes.push(i);
		}

		int deleted_num = 0;
		while (!deleted_nodes.empty()) {
			++deleted_num;
			int node = deleted_nodes.front();

			// decrease node in_degree that include this node
			for (int i = 0; i < graph[node].size(); ++i) {
				int nei_node = graph[node][i];
				if (--in_degree[nei_node] == 0)
					deleted_nodes.push(nei_node);
			}
			deleted_nodes.pop();
		}
		return deleted_num == numCourses;
	}
};
