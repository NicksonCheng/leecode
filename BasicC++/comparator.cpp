/*
    1. Lambda function methods
    Lambda:
    [capture](parameter_list) -> return_type {
        // function body
    };
*/
#include <iostream>
using namespace std;
int main() {
	vector<pair<int, int>> v = {{1, 2}, {3, 1}, {2, 5}};

	// sort pair with lambda comparator
	sort(v.begin(), v.end(),
	     [](const pair<int, int> &a, const pair<int, int> &b) {
		     return a.second < b.second;
	     });
}

/*
    2. struct comparator
*/
struct Compare {
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
		return a.second > b.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
