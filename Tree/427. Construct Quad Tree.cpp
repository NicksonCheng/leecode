/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/
/*
    如果grid cell都一樣-> leaf
        有cell不一樣-> node

    1. sol.1: 先travers目前grid, 一但出現不一樣的數字,就進行切割,
   然後recursive直到leaf滿足條件
*/
class Solution {
  public:
	Node *construct(vector<vector<int>> &grid) {
		return dfs(grid, 0, grid[0].size(), 0, grid.size());
	}
	Node *dfs(vector<vector<int>> &grid, int l, int r, int t, int b) {
		// check if all cell number same
		int num = grid[t][l];
		// cout << l << " " << r << " " << t << " " << b << endl;
		Node *node = new Node(num, true);
		for (int i = t; i < b; ++i) {
			for (int j = l; j < r; ++j) {
				// 切割4塊
				if (grid[i][j] != num) {
					node->isLeaf = false;
					int col_middle =
					    l + (r - l) / 2; // 這邊切割middle要注意！！
					int row_middle = t + (b - t) / 2;
					node->topLeft = dfs(grid, l, col_middle, t, row_middle);
					node->topRight = dfs(grid, col_middle, r, t, row_middle);
					node->bottomLeft = dfs(grid, l, col_middle, row_middle, b);
					node->bottomRight = dfs(grid, col_middle, r, row_middle, b);
					return node;
				}
			}
		}
		return node;
	}
};