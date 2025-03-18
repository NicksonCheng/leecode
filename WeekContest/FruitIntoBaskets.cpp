#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
	int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
		int rest_fruits = fruits.size();
		for (int i = 0; i < fruits.size(); ++i) {
			for (int j = 0; j < baskets.size(); ++j) {
				if (fruits[i] <= baskets[j]) {
					baskets.erase(baskets.begin() + j);
					--rest_fruits;

					break;
				}
			}
		}
		return rest_fruits;
	}
};

int main() {
	vector<int> fruits = {4};
	vector<int> baskets = {4};
	Solution sol;
	cout << sol.numOfUnplacedFruits(fruits, baskets) << endl;
}
