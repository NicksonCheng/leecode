#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int len = str.length();
        for (int i = 0; i < len; ++i) {
            int reverse_idx = len - 1 - i;
            if (str[i] != str[reverse_idx])
                return false;
        }
        return true;
    }
};
int main(int argc, char const *argv[]) {
    /* code */
    Solution solution;
    cout << solution.isPalindrome(1234321) << endl;

    return 0;
}
