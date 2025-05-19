/*
    1. brutal force : the minimum capacity must > max packages weight, we
gradually increasing our capcity and try the days of shippment time O(n * k), n
= weight.size(), k = number of try

    sol.2. Binary search
       max_capacity -> total sum
       min_capacity -> max element

       find the first element > day(l + 1 == mini capacity)

🧠 時間複雜度：O(N * logS)
N 是 weights.size()
S = total_weight - max_weight 的範圍大小
*/
class Solution {
  public:
	int shipWithinDays(vector<int> &weights, int days) {
		int n = weights.size();
		long long min_capacity = *max_element(weights.begin(), weights.end());
		long long max_capacity;
		for (int &w : weights)
			max_capacity += w;
		// int period = n / days;
		// for(int i = 0; i + period <= n; i += period){
		//     int c = 0;
		//     for(int j = i; j < period; ++j){
		//         c += weights[j];
		//     }
		//     max_capacity = max(max_capacity, c);
		// }
		long long l = min_capacity;
		long long r = max_capacity;
		// find lower bound, >= firstplace
		cout << l << " " << r << endl;
		while (l <= r) {

			long long m = l + (r - l) / 2;
			cout << l << " " << m << " " << r << endl;
			int total_weights = 0;
			int d = 0;
			for (int i = 0; i < weights.size(); ++i) {
				// cout << "total:" << total_weights << endl;
				if (total_weights + weights[i] > m) {
					total_weights = weights[i];
					++d;
				} else
					total_weights += weights[i];
			}
			// if there still remaining package, we still need to count the day
			// of shippment
			if (total_weights > 0)
				++d;
			// cout << "day:" <<d <<endl;
			//  find the first element <= days
			if (d <= days)
				r = m - 1;
			else
				l = m + 1;
		}
		return l;
	}
};