/*
    0->1
    1->2
    0->2

    0->1->2
    0->2->1

    每次可以打開幾個就有幾種方法


*/
#include <iostream>
#include <queue>
using namespace std;
class Solution {
  public:
	int countPermutations(vector<int> &complexity) {
		int count = 1;
		int n = complexity.size();
		vector<vector<int>> graph(n);
		queue<int> q;
		q.push(0);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j)
					continue;
				if (complexity[i] < complexity[j])
					graph[i].push_back(j);
			}
		}
		int visit_pc = 0;
		while (!q.empty()) {
			int pc = q.front();
			q.pop();
			++visit_pc;
			int num_neis = graph[pc].size();
			count *= num_neis;
			for (int &nei : graph[pc])
				q.push(nei);
		}
		return visit_pc == n ? count : 0;
	}
};