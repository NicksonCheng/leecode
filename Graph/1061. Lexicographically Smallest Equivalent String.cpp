// 超時
/*
    union find, parent char 大的union 在parent char 小的上面
*/
struct UnionFind {
  public:
	vector<char> parent;
	UnionFind() {
		for (int i = 0; i < 26; ++i) {
			parent.push_back('a' + i);
		}
	};
	char Find(char c) {
		int idx = c - 'a';
		if (parent[idx] != c)
			parent[idx] = Find(parent[idx]);
		return parent[idx];
	};
	void Union(char a, char b) {
		char root_a = Find(a);
		char root_b = Find(b);

		if (root_a == root_b) {
			// already union
			return;
		}
		if (root_a < root_b) {
			parent[root_b - 'a'] = root_a;
		} else {
			parent[root_a - 'a'] = root_b;
		}
	};
};
class Solution {
  public:
	string smallestEquivalentString(string s1, string s2, string baseStr) {
		UnionFind uf;
		for (int i = 0; i < s1.length(); ++i) {
			char a = s1[i];
			char b = s2[i];
			uf.Union(a, b);
		}
		string res = "";
		for (int i = 0; i < baseStr.length(); ++i) {
			res += uf.Find(baseStr[i]);
		}
		return res;
	}
};