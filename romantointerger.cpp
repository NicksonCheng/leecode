
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
typedef struct Hashmap {
    /* data */
} Hashmap;

class Solution {
   public:
    int romanToInt(string s) {
        int sum = 0;
        unordered_map<char, int> hashmap;
        char roam[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int number[7] = {1, 5, 10, 50, 100, 500, 1000};
        for (int i = 0; i < 7; ++i) {
            char key = roam[i];
            int val = number[i];
            hashmap[key] = val;
        }
        for (int i = 0; i < s.length(); ++i) {
            char key = s[i];
            bool flag1 = false, flag2 = false, flag3 = false;
            if (i + 1 < s.length()) {
                flag1 = (key == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X'));  // IV IX
                flag2 = (key == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C'));
                flag3 = (key == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'));
            }
            (flag1 || flag2 || flag3) ? sum -= hashmap[key] : sum += hashmap[key];
        }
        cout << sum << endl;
        return sum;
    }
    string intTORoman(int num) {
        char roam[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int number[7] = {1, 5, 10, 50, 100, 500, 1000};
    }
};
int main(int argc, char const *argv[]) {
    /* code */
    string input;
    Solution solution;
    cin >> input;
    solution.romanToInt(input);
    return 0;
}
