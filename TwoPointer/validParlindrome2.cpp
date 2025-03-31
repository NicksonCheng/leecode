// hint
// 1. 先check 每個left right 的字母是否一樣
// 2. 如果不一樣, 就看左右各自拿掉的substring 是否有一存在palindrome
// 3. 如果都不存在, 表示拿掉這個char依然沒用直接return false
class Solution {
  public:
	bool validPalindrome(string s) {
		int n = s.length();
		int l = 0;
		int r = n - 1;

		while (l < r) {
			if (s[l] != s[r]) {
				return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
			}
			++l;
			--r;
		}
		return true;
	}

  private:
	bool isPalindrome(string s, int l, int r) {
		while (l < r) {
			if (s[l] != s[r])
				return false;
			++l;
			--r;
		}
		return true;
	}
};