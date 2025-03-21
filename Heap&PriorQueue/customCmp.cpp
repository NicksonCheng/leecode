#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Custom comparator for max heap (based on second value of pair)
struct Compare {
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
		return a.second <
		       b.second; // Max heap: higher second value has higher priority
	}
};

int main() {
	// Priority queue using custom comparator
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

	// Insert elements (first: ID, second: priority)
	pq.push({1, 100});
	pq.push({2, 300});
	pq.push({3, 200});
	pq.push({4, 150});

	// Print elements based on priority (second value)
	cout << "Priority Queue Elements (sorted by second value in descending "
	        "order):\n";
	while (!pq.empty()) {
		cout << "ID: " << pq.top().first << ", Priority: " << pq.top().second
		     << endl;
		pq.pop();
	}

	return 0;
}
