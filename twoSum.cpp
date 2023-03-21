#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    /* code */
    vector<int> nums;
    vector<int> ans;
    unordered_map<int, int> hash;
    int target = 0;
    cin >> target;
    while (true) {
        /* code */
        int num = 0;
        cin >> num;
        nums.push_back(num);
        if (cin.peek() == '\n') break;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (hash.find(nums[i]) != hash.end()) {
            ans.push_back(i);
            ans.push_back(hash[nums[i]]);
        }
        hash[target - nums[i]] = i;
    }
    cout << ans[0] << ans[1] << endl;

    return 0;
    // dick
}
