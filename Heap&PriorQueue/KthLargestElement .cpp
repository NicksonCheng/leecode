#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class KthLargest {
  public:
	KthLargest(int k, vector<int> &nums) {
		this->k = k;
		for (int i = 0; i < nums.size(); ++i) {
			min_heap.push(nums[i]);

			// keep k-th largest element on the top
			if (min_heap.size() > k)
				min_heap.pop();
		}
	}

	int add(int val) {
		min_heap.push(val);
		if (min_heap.size() > this->k)
			min_heap.pop();
		return min_heap.top();
	}

  private:
	int k = 0;
	priority_queue<int, vector<int>, greater<int>> min_heap;
};

int main() {
	vector<int> arr = {1, 2, 3, 3, 8, 7, 6};
	KthLargest *KL = new KthLargest(3, arr);
	cout << KL->add(8) << endl;
	return 0;
}