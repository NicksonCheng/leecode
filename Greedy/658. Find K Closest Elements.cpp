// proficient
/*
    already sort, count each distance, start from min distance,
    expand from lower distance
    if(left_dis == right_dis, expand left)

    time O(n)
    space O(n)
*/
class Solution {
  public:
	vector<int> findClosestElements(vector<int> &arr, int k, int x) {
		int n = arr.size();
		vector<int> distance(n, 0);
		pair<int, int> min_dis = {INT_MAX, -1}; // {distance, index}
		for (int i = 0; i < arr.size(); ++i) {
			distance[i] = abs(arr[i] - x);
			if (distance[i] < min_dis.first) {
				min_dis = {distance[i], i};
			}
		}

		// start from minimal distance
		int l = min_dis.second - 1;
		int r = min_dis.second + 1;
		--k; // take first element
		vector<int> res;
		while (k > 0) {
			if (l >= 0 && r < n) {
				// both compare
				distance[r] < distance[l] ? ++r : --l;
			}
			// only one direction
			else if (l >= 0) {
				--l;
			} else if (r < n) {
				++r;
			} else
				break;
			--k;
		}
		++l;
		--r;
		for (int i = l; i <= r; ++i)
			res.push_back(arr[i]);
		return res;
	}
};