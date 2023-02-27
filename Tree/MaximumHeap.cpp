#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    /* data */
};
void insert(TreeNode*& root, int v) {
    TreeNode* node = new TreeNode();
    node->value = v;
    node->left = NULL;
    node->right = NULL;

    if (root == NULL) {
        root = node;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        /* code */
        TreeNode* curr = q.front();
        // cout << "curr=" << curr->value << endl;
        q.pop();
        if (!curr->left) {
            curr->left = node;
            break;
        } else
            q.push(curr->left);
        if (!curr->right) {
            curr->right = node;
            break;
        } else
            q.push(curr->right);
    }
    // cout << "--------------" << endl;
}
void DFS_traversal(TreeNode* root, string type = "root") {
    if (root != NULL) {
        cout << type << ":" << root->value << endl;
        DFS_traversal(root->left, "left");
        DFS_traversal(root->right, "right");
    }
}
void BFS_traversal(TreeNode* root, string type = "root") {
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        /* code */
        cout << "level:" << level << "----------" << endl;
        TreeNode* node = q.front();
        cout << node->value << endl;

        q.pop();
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
        level += 1;
    }
}
int main(int argc, char const* argv[]) {
    TreeNode* root = NULL;
    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    BFS_traversal(root);
    return 0;
}
