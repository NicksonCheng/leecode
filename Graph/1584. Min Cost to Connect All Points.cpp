/*
    1. Kruskal’s Algorithm
    2. prim's algorithm
*/
class UnionFind {
  public:
	vector<int> parent;
	vector<int> rank;
	UnionFind(int x) {
		for (int i = 0; i < x; ++i)
			parent.push_back(i);
		rank.resize(x, 1);
	};
	int Find(int x) {
		if (parent[x] != x)
			parent[x] = Find(parent[x]);
		return parent[x];
	};
	bool Union(int x, int y) {
		int root_x = Find(x);
		int root_y = Find(y);
		if (root_x == root_y)
			return false; // this node is already in union set
		if (rank[root_x] > rank[root_y])
			parent[root_y] = root_x;
		else if (rank[root_x] < rank[root_y])
			parent[root_x] = root_y;
		else {
			parent[root_y] = root_x;
			++rank[root_x];
		}
		return true;
	};
};
/*
    1. prim's algorithm
*/
class Solution {
  public:
	int minCostConnectPoints(vector<vector<int>> &points) {
		// calculate all edge
		int n = points.size();
		vector<tuple<int, int, int>> edges(n);
		// calculate all edges
		for (int i = 0; i < n; ++i) {
			for (int j = 1; j < n; ++j) {
				int w = abs(points[i][0] - points[j][0]) +
				        abs(points[i][1] - points[j][1]);
				edges.push_back({w, i, j});
			}
		}
		// sort edges increasing
		sort(edges.begin(), edges.end(),
		     [](tuple<int, int, int> &a, tuple<int, int, int> &b) {
			     return get<0>(a) < get<0>(b);
		     });
		// union from edges, and union will detect if this edge will be
		// cycle(already in component)
		UnionFind uf(n);
		int cost = 0;
		for (int i = 0; i < edges.size(); ++i) {
			auto [w, u, v] = edges[i];
			if (uf.Union(u, v)) {
				cost += w;
			}
		}

		return cost;
	}
};
/*
    1. prim's algorithm
*/
class Solution {
  public:
	int minCostConnectPoints(vector<vector<int>> &points) {
		// calculate all edge
		int n = points.size();
		vector<vector<pair<int, int>>> graph(n); // {weight, node}
		unordered_set<int> visit;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
		    min_heap;
		// create completed graph with all edge weight
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int w = abs(points[i][0] - points[j][0]) +
				        abs(points[i][1] - points[j][1]);
				graph[i].push_back({w, j});
				graph[j].push_back({w, i});
			}
		}
		// start from random node(start from node 0)
		min_heap.push({0, 0});
		int cost = 0; // check if all node is spanning;
		while (visit.size() < n && !min_heap.empty()) {
			// used minimum weight every time;
			auto [w, node] = min_heap.top();
			min_heap.pop();
			// cout << node << " " << w << endl;
			if (visit.find(node) != visit.end())
				continue;
			cost += w;
			visit.insert(node);
			for (auto &nei : graph[node]) {
				min_heap.push(nei);
			}
		}
		return cost;
	}
};