#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode invertTree(TreeNode* root) {
    }
    void createTree(TreeNode* root) {
        int r[7] = {4, 2, 7, 1, 3, 6, 9};
    }
};
int main(int argc, char const argv[]) {
    Solution sol = new Solution();
    sol.invertTree();
    return 0;
}
