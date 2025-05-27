/*
    trie 為一種tree data structure, 藉由跟hashtable結合
    讓每個node都像是字典查詢一樣往下尋找words,
   end_word表示這個node能夠形成合法word

    n = word.length(), number of words = m
    time complexity, insert O(n), search O(n) startswith O(n)
    space, O(n * m)
*/
class TrieNode {
  public:
	unordered_map<char, TrieNode *> children;
	bool end_word = false;
};
class Trie {
  public:
	TrieNode *root;
	Trie() { root = new TrieNode(); }

	void insert(string word) {
		TrieNode *cur = root;
		for (char &c : word) {
			if (cur->children.count(c) == 0) {
				// insert new key
				cur->children[c] = new TrieNode();
			}
			cur = cur->children[c];
		}
		cur->end_word = true; // effective word end in this node
	}

	bool search(string word) {
		TrieNode *cur = root;
		for (char &c : word) {
			if (cur->children.count(c) == 0)
				return false;
			cur = cur->children[c];
		}
		return cur->end_word;
	}

	bool startsWith(string prefix) {
		TrieNode *cur = root;
		for (char &c : prefix) {
			if (cur->children.count(c) == 0)
				return false;
			cur = cur->children[c];
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */