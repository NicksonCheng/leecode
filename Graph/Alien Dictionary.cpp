// proficient
/*
    已經sorting, 兩兩比較建立character graph, 如果有cycle 代表字典錯誤

    透過topology sort將dictionary dump出來 return

    n = words.size(), m = max word length()
    time: O(n * m)
    space: O(1)
*/
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
  public:
	string foreignDictionary(vector<string> &words) {
		// create dictionary graph
		vector<vector<int>> graph(26);
		vector<int> indegree(26, 0);
		for (int i = 0; i < words.size() - 1; ++i) {
			int j1 = 0;
			int j2 = 0;
			while (j1 < words[i].length() && j2 < words[i + 1].length()) {
				char c1 = words[i][j1];
				char c2 = words[i + 1][j2];
				if (c1 != c2) {
					graph[c1 - 'a'].push_back(c2 - 'a');
					++indegree[c2 - 'a'];
					break;
				}
				++j1;
				++j2;
			}
			// dictionary sorting錯誤, [abcde, abc]
			if (j2 == words[i + 1].length() && j1 < words[i].length())
				return "";
		}

		// derive the order of letter in dictionary
		queue<int> q;
		string res = "";
		int delete_nodes = 0;
		for (int i = 0; i < indegree.size(); ++i) {
			if (indegree[i] == 0)
				q.push(i);
		}

		while (!q.empty()) {
			int c = q.front(); // char in interger index
			q.pop();
			++delete_nodes;
			res += char(c + 'a');
			// delete node
			for (int &nei : graph[c]) {
				if (--indegree[nei] == 0) {
					q.push(nei);
				}
			}
		}
		cout << delete_nodes << endl;
		// delete_nodes > 0 -> there is still node not deleted, contain cycle
		return delete_nodes == 26 ? res : "";
	}
};
