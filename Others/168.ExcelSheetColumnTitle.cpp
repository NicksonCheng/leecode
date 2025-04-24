// hint
class Solution {
  public:
	string convertToTitle(int columnNumber) {
		string res = "";

		while (columnNumber > 0) {
			--columnNumber; // 26進位陷阱, 因為excel表A->1 是從1開始,
			                // 所以每次取於數都要先-1才可以
			int remainder = columnNumber % 26;
			char cur_excel_char = 'A' + remainder;
			res = cur_excel_char + res;

			columnNumber /= 26;
		}
		return res;
	}
};