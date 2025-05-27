
/*
    遇到.(all letter) 就必須每個childrean 都 traverse一遍

    n = word.length(), number of words = m
    addWord O(n)

    search O(n * 26)->O(n), 有可能遇到. 然後全部字母都要traverse一遍

    space O(m)
*/
class TrieNode {
  public:
	unordered_map<char, TrieNode *> children;
	bool end_word = false;
};
class WordDictionary {
  public:
	TrieNode *root;
	WordDictionary() { root = new TrieNode(); }

	void addWord(string word) {
		TrieNode *cur = root;
		for (char &c : word) {
			if (cur->children.count(c) == 0)
				cur->children[c] = new TrieNode();
			cur = cur->children[c];
		}
		cur->end_word = true;
	}
	bool dfs(string word, TrieNode *cur, int idx) {
		for (int i = idx; i < word.length(); ++i) {
			char c = word[i];
			// cout << c << " " << endl;
			if (c == '.') {
				// all childrean need to be traverse
				for (auto &child : cur->children) {
					if (dfs(word, child.second, i + 1))
						return true;
				}
				return false;
			} else {
				if (cur->children.count(c) == 0)
					return false;
				cur = cur->children[c];
			}
		}
		return cur->end_word;
	}
	bool search(string word) {
		TrieNode *cur = root;
		return dfs(word, cur, 0);
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */