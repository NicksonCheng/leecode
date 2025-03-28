class TrieNode {
  public:
	unordered_map<char, TrieNode *> children;
	bool end_word = false;
};
class PrefixTree {
  public:
	TrieNode *root;
	PrefixTree() { root = new TrieNode(); }

	void insert(string word) {
		TrieNode *head = root;
		for (int i = 0; i < word.length(); ++i) {
			char w = word[i];
			if (head->children.find(w) == head->children.end()) {
				head->children[w] = new TrieNode();
			}
			head = head->children[w];
		}
		// 是 每個 insert 自己的end, fuck, fuckmydick都有各自的end不是共用的
		head->end_word = true;
	}

	bool search(string word) {
		TrieNode *head = root;
		for (int i = 0; i < word.length(); ++i) {
			char w = word[i];
			if (head == nullptr || head->children.count(w) == 0)
				return false;
			head = head->children[w];
		}

		return head->end_word;
	}

	bool startsWith(string prefix) {
		TrieNode *head = root;
		for (int i = 0; i < prefix.length(); ++i) {
			char w = prefix[i];
			if (head == nullptr || head->children.count(w) == 0)
				return false;
			head = head->children[w];
		}
		return true;
	}
};
