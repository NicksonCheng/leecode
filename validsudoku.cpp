/* solution https://skyyen999.gitbooks.io/-leetcode-with-javascript/content/questions/36md.html*/
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        char boxes[9][9];
        for (int i = 0; 9; ++i) {
            vector<char> row;

            // column valid
            // if (!isVaild(board[i])) return false;
            // row valid
            for (int j = 0; j < 9; ++j) {
                row.push_back(board[i][j]);
                int boxId = (i / 3) * 3 + j / 3;
                boxes[boxId][j] = board[i][j];
            }
            if (!isVaild(row)) return false;
        }
        // box valid
        for (int k = 0; k < 9; ++k) {
            vector<char> box(begin(boxes[k]), end(boxes[k]));
            if (!isVaild(box)) return false;
        }
    }

   private:
    bool isVaild(vector<char> map) {
        bool visit[9];
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < map.size(); ++i) {
            if (map[i] == '.') continue;
            if (visit[i])
                return false;
            else
                visit[i] = true;
        }
        return true;
    }
};
int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
