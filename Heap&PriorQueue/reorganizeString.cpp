// proficient
/*
    先用heap去存每個char出現的次數
    max_heap去儲存每次都拿top-2的char來組合, 如果拿到兩個相同的char代表失敗

    Sol2: 用greedy方法, 先找出現最多次的char然後分別放在偶數區域0246,
   再其他的一一填入直到map為空
*/
typedef struct Compared {
	bool operator()(pair<char, int> a, pair<char, int> b) {
		return a.second < b.second;
	}
} Compared;
class Solution {
  public:
	string reorganizeString(string s) {
		unordered_map<char, int> char_map;
		priority_queue<pair<char, int>, vector<pair<char, int>>, Compared>
		    max_heap;
		string res;
		// count char number first
		for (int i = 0; i < s.length(); ++i) {
			++char_map[s[i]];
		}
		// push
		for (auto &m : char_map) {
			max_heap.push(m);
		}

		// top two combination
		while (!max_heap.empty()) {
			pair<char, int> top1 = max_heap.top();
			max_heap.pop();
			// if only one char in heap(char count == 1-> true, > 1->false)
			if (max_heap.empty()) {
				if (top1.second > 1)
					return "";
				else {
					res += top1.first;
					break;
				}
			}
			pair<char, int> top2 = max_heap.top();
			max_heap.pop();

			// update string combination
			res += top1.first;
			res += top2.first;
			--top1.second;
			--top2.second;

			// still has char
			if (top1.second > 0)
				max_heap.push(top1);
			if (top2.second > 0)
				max_heap.push(top2);
		}
		return res;
	}
};