// proficient
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
    按照root->left->right進行encoding, 如果nullptr用|代替, num之間要用,分隔

    decoding時用一個global index去推進
*/
class Codec {
  public:
	// Encodes a tree to a single string.
	string serialize(TreeNode *root) {
		this->node_code = "";
		encoding(root);
		return node_code;
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(string data) {
		cout << data << endl;
		this->node_code = data;
		this->i = 0;
		return decoding();
	}

  private:
	string node_code;
	int i = 0;
	void encoding(TreeNode *node) {
		if (node == nullptr) {
			node_code.push_back('|');
			return;
		}
		stringstream ss;
		ss << node->val;
		string s;
		ss >> s;
		node_code += s + ',';
		encoding(node->left);
		encoding(node->right);
	}
	TreeNode *decoding() {
		if (i >= node_code.length() || node_code[i] == '|') {
			++i;
			return nullptr;
		}

		string num_code;
		while (node_code[i] != ',') {
			num_code += node_code[i++];
		}
		++i; //  ',' is already seen
		int val = stoi(num_code);

		TreeNode *node = new TreeNode(val);
		node->left = decoding();
		node->right = decoding();
		return node;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));