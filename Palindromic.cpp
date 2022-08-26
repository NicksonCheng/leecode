/* DP table for this programming https://myinterview.guru/leetcode-5-longest-palindromic-substring-17717b5db2c2*/
#include <cstring>
#include <iostream>
using namespace std;
class Solution {
   public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int begin = 0, end = 0;
        int n = s.length();
        bool dp[n][n];  // initialize the dp table for palindromic
        memset(dp, false, sizeof(dp));
        for (int j = 0; j < s.length(); ++j) {
            dp[j][j] = true;  // diagonse
            for (int i = 0; i < j; ++i) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {  // check subtable dp[i+1][j-1]
                    dp[i][j] = true;
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        begin = i;
                        end = j;
                    }
                }
            }
        }
        cout << begin << " " << end << endl;
        cout << s.substr(begin, end - begin + 1) << endl;
        return s.substr(begin, end - begin + 1);
    }
};
int main(int argc, char const *argv[]) {
    Solution solution;
    string input;
    cin >> input;
    string str = solution.longestPalindrome(input);
    return 0;
}
