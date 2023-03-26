
#include <math.h>

#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int s = matrix.size();

        // reverse
        for (int i = 0; i < (s / 2); ++i) {
            vector<int> tmp = matrix[i];
            matrix[i] = matrix[s - i - 1];
            matrix[s - i - 1] = tmp;
        }
        // transpose
        for (int i = 0; i < s; ++i) {
            for (int j = i + 1; j < s; ++j) {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
        for (int i = 0; i < s; ++i) {
            for (int j = 0; j < s; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main(int argc, char const* argv[]) {
    /* code */
    int arr[4][4] = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    vector<vector<int>> vec;
    for (int i = 0; i < 4; ++i) {
        vector<int> tmp;
        for (int j = 0; j < 4; ++j) {
            tmp.push_back(arr[i][j]);
        }
        vec.push_back(tmp);
    }
    Solution solution;
    solution.rotate(vec);
    return 0;
}
