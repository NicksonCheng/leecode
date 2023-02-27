#include <string.h>

#include <iostream>
using namespace std;
struct Node {
    /* data */
    int value;
    Node* left;
    Node* right;
    Node(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }
};
void inorderTraversal(Node*& root, string type) {
    if (root != NULL) {
        inorderTraversal(root->left, "left");
        cout << type << ":" << root->value << endl;

        inorderTraversal(root->right, "right");
    } else {
        // cout << "leaf" << endl;
    }
}
void insert(Node*& root, int value) {
    Node* node = new Node(value);

    if (root == NULL) {
        root = node;
    } else {
        if (value < root->value) {
            insert(root->left, value);
        } else {
            insert(root->right, value);
        }
    }
}
int main(int argc, char const* argv[]) {
    Node* root = NULL;
    while (true) {
        /* code */
        int v = 0;
        cin >> v;
        if (v == 0) break;
        insert(root, v);
        // cout << root->value << endl;
    }
    inorderTraversal(root, "root");
    return 0;
}
