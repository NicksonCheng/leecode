class Solution {
  public:
	string removeSpecialCharacter(string s) {
		int j = 0;
		for (int i = 0; i < s.size(); i++) {

			// Store only valid characters
			if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
			    (s[i] >= '0' && s[i] <= '9')) {
				s[j] = s[i];
				j++;
			}
		}
		return s.substr(0, j);
	}

	bool isPalindrome(string s) {

		s = removeSpecialCharacter(s);
		int len = s.length();
		cout << s << endl;
		for (int i = 0; i < len; ++i) {
			if (tolower(s[i]) != tolower(s[len - i - 1])) {
				cout << s[i] << " " << s[len - i - 1] << endl;
				return false;
			}
		}
		return true;
	}
};
