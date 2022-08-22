#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        bool visit[256] = {0};  // record the visit position
        int i = 0;
        int j = 0;
        int max_sub = 0;

        while (i < s.length() && j < s.length()) {
            int pos = int(s[i]);
            if (visit[pos]) {
                // found

                // count maximal length
                cout << i << " " << j << endl;
                int sub_len = i - j;
                if (sub_len > max_sub) max_sub = sub_len;
                for (int k = j; k <= i; ++k) visit[s[k]] = false;
                ++j;

                i = j;
            } else {
                // not found
                visit[pos] = true;
                ++i;
            }
            if (i >= s.length()) {
                cout << i << " " << j << endl;
                int sub_len = i - j;
                if (sub_len > max_sub) max_sub = sub_len;
            }
        }
        cout << max_sub << endl;
        return max_sub;
    }
};
int main(int argc, char const *argv[]) {
    /* code */
    Solution solution;
    string str = "tmmzuxt";
    solution.lengthOfLongestSubstring(str);

    return 0;
}
