// proficient
/*
    greedy problem, NS / WE compared together,
    we change the smaller count of direction first

    time complexity
    n = s.length
    total time complexity O(n)
    space O(1)
*/
class Solution {
  public:
	int maxDisSubstr(unordered_map<char, int> &dir_count, int k) {
		// start change from smallest direction
		int min_x = min(dir_count['N'], dir_count['S']);
		int max_x = max(dir_count['N'], dir_count['S']);
		int min_y = min(dir_count['W'], dir_count['E']);
		int max_y = max(dir_count['W'], dir_count['E']);
		int num_change;
		if (min_x < min_y) {
			num_change = min(k, min_x);
			max_x += num_change;
			min_x -= num_change;
			k -= num_change;

			if (k > 0) {
				num_change = min(k, min_y);
				max_y += num_change;
				min_y -= num_change;
			}
		} else {
			num_change = min(k, min_y);
			max_y += num_change;
			min_y -= num_change;
			k -= num_change;

			if (k > 0) {
				num_change = min(k, min_x);
				max_x += num_change;
				min_x -= num_change;
			}
		}
		// cout << max_x << ' ' << min_x << ' ' << max_y << ' ' << min_y <<
		// endl;
		return max_x - min_x + max_y - min_y;
	}
	int maxDistance(string s, int k) {
		unordered_map<char, int> dir_count;
		int max_distance = 0;
		for (char &c : s) {
			++dir_count[c];
			int dis = maxDisSubstr(dir_count, k);
			// cout << dis << endl;
			max_distance = max(dis, max_distance);
		}
		return max_distance;
	}
};