#include <iostream>
using namespace std;
class Solution {
  public:
	int reverseDegree(string s) {
		int sum = 0;
		for (int i = 0; i < s.length(); ++i) {
			sum += (i + 1) * ('z' - s[i] + 1);
		}
		return sum;
	}
};

int main() {
	Solution sol;
	cout << sol.reverseDegree("zaza") << endl;
}