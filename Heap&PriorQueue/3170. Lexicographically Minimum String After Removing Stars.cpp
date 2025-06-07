// proficient
/*
    n = s.length()
    先用2-Dvector紀錄每個char出現位置
    每次遇到star就從最小且最右邊刪除
    最後全部dump到min heap裡面再push到res string, time: O(nlogn), space O(n)
*/
#define Pair pair<int, char> // {index in s, character}
class Solution {
  public:
	string clearStars(string s) {
		vector<vector<int>> char_index(26);
		priority_queue<Pair, vector<Pair>, greater<>> min_heap;
		// traverse s and record character index
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '*') {
				// traverse from smallest char, if there exist index, we remove
				// one of them
				for (int j = 0; j < 26; ++j) {
					if (char_index[j].size() > 0) {
						char_index[j].pop_back();
						break;
					}
				}
			} else
				char_index[s[i] - 'a'].push_back(i);
		}

		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < char_index[i].size(); ++j) {
				min_heap.push({char_index[i][j], char(i + 'a')});
			}
		}
		string res;
		while (!min_heap.empty()) {
			res += min_heap.top().second;
			min_heap.pop();
		}
		return res;
	}
};