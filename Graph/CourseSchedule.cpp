
// hint
/*
    每個couse都去走一遍DFS, 檢查看看會不會出現重複element(hashset), 如果有return
   false;

    必須增加visit避免重複訪問
*/
/*
    create
    unordered_set去儲存目前topology
    visit表示node已經走過
    dfs每個node偵測是否在topology中(是否有cycle)
    5/3 review
*/
class Solution {
  public:
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
		// create graph
		vector<vector<int>> graph(numCourses);
		for (auto &p : prerequisites) {
			int u = p[1];
			int v = p[0];
			graph[u].push_back(v);
		}

		// dfs every node, if visit, return true(already detected)
		vector<bool> visit(numCourses, false);
		for (int i = 0; i < numCourses; ++i) {
			unordered_set<int> topologys; // detect cycle
			if (!dfs(graph, visit, topologys, i))
				return false;
		}
		return true;
	}
	bool dfs(vector<vector<int>> &graph, vector<bool> &visit,
	         unordered_set<int> &topologys, int node) {
		if (visit[node])
			return true;
		// detect cycle(encounter same node)
		if (topologys.find(node) != topologys.end())
			return false;
		topologys.insert(node);
		for (int i = 0; i < graph[node].size(); ++i) {
			int nei_node = graph[node][i];
			if (!dfs(graph, visit, topologys, nei_node))
				return false;
		}
		// after dfs, set visit true, and remove out from topologys
		visit[node] = true;
		topologys.erase(node);
		// no cycle
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
