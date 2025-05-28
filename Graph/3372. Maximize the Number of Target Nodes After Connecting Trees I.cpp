/*
    題目要求, 每個first tree的node都去跟tree 2 任意node連接一遍,
    找出each node可以在k edge path 裡連接最多的node

    sol.1 Tree 1, Tree 2 先自己做一次BFS, 紀錄每個node k edges可以抵達的node數量
          connect的時候只需要 (tree1->node < K + tree2->node < K - 1 即可,
   最後兩個加總+2(這兩個connected node也要算))

          time complexity O(n^2 + m^2)
*/
class Solution {
  public:
	void countMaxNodes(vector<int> &ans, vector<vector<int>> &edges, int k) {
		vector<vector<int>> graph(1000);
		for (auto &e : edges) {
			graph[e[0]].push_back(e[1]);
			graph[e[1]].push_back(e[0]);
		}
		for (int i = 0; i < graph.size(); ++i) {
			if (graph[i].size() == 0)
				break; // 只有i - 1這麼多的node
			// 開始BFS計算k path內node的數量
			int num_nodes = 0;
			int level = 0;
			queue<int> q;
			vector<bool> visit(1000, false);
			q.push(i);
			while (!q.empty()) {
				int size = q.size();
				for (int j = 0; j < size; ++j) {
					int node = q.front();
					q.pop();
					++num_nodes;
					visit[node] = true;
					for (int &nei : graph[node]) {
						if (!visit[nei])
							q.push(nei);
					}
				}
				if (++level > k)
					break;
			}
			ans.push_back(num_nodes);
		}
	}
	vector<int> maxTargetNodes(vector<vector<int>> &edges1,
	                           vector<vector<int>> &edges2, int k) {

		vector<int> ans1;
		vector<int> ans2;
		countMaxNodes(ans1, edges1, k);
		countMaxNodes(ans2, edges2, k - 1);
		if (k == 0)
			return ans1;
		// for(int &item : ans1)
		//     cout << item << " ";
		// cout << endl;
		// for(int &item : ans2)
		//     cout << item << " ";
		// cout << endl;
		for (int i = 0; i < ans1.size(); ++i) {
			int path_1 = ans1[i];
			for (int j = 0; j < ans2.size(); ++j) {
				int path_2 = ans2[j];
				ans1[i] = max(ans1[i], path_1 + path_2);
			}
			// ans1[i] += 2; // connection node (u,v) need to be consider,
			// 這裡在BFS已經將自己算進去了
		}
		return ans1;
	}
};