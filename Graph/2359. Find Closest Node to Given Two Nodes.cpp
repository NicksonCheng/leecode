/*
    DFS, 計算每個node的距離, 題目要找 max(dis[node, node1], dis[node,node2]) 的
   min 會有點難懂
*/
class Solution {
  public:
	vector<int> getDistances(vector<int> &edges, int start) {
		vector<int> dis(edges.size(), -1);
		int d = 0;
		while (start != -1 && dis[start] == -1) { // 避免cycle
			dis[start] = d++;
			start = edges[start];
		}
		return dis;
	}

	int closestMeetingNode(vector<int> &edges, int node1, int node2) {
		vector<int> dist1 = getDistances(edges, node1);
		vector<int> dist2 = getDistances(edges, node2);
		pair<int, int> min_dis = {-1, INT_MAX};

		for (int i = 0; i < dist1.size(); ++i) {
			if (dist1[i] != -1 && dist2[i] != -1) {
				int max_dis = max(dist1[i], dist2[i]);
				if (max_dis < min_dis.second)
					min_dis = {i, max_dis};
				else if (max_dis == min_dis.second && i < min_dis.first)
					min_dis = {i, max_dis};
			}
		}
		return min_dis.first;
	}
};
