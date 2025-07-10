/*
    n = s.length()
    k = shifts.size()
    brutal force, shift char by all shifts, time O(n * k)

    sol.2 suffix sum, calculate suffix for all shifits and shift char by s
    time O(n) two pass, space O(n)
*/
class Solution {
  public:
	string shiftingLetters(string s, vector<int> &shifts) {
		int n = s.length();
		int k = shifts.size();
		vector<long long> suffix(k, 0);
		suffix[k - 1] = shifts[k - 1];
		for (int i = k - 2; i >= 0; --i) {
			suffix[i] = suffix[i + 1] + shifts[i];
		}

		for (int i = 0; i < n; ++i) {
			int shift_char = (s[i] + suffix[i] - 'a') % 26;
			// cout << suffix[i] << " " << shift_char << endl;
			s[i] = 'a' + shift_char;
		}
		return s;
	}
};