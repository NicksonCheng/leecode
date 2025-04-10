// hint
/*
 邏輯正確, coding錯誤
Sol1 hashmap & Greedy: 用C++ STL map, 這是一個排序好的hashtable,
根據這個hashtable, 每次都從最小的key開始跑(greedy),
如果可以順利跑完groupSize代表group成立, 如果hashtable 為空 i == groupsize,
代表成立 time complexity: map 是用紅黑樹做的O(logn),
每張牌最多會被訪問一次、查詢一次、刪除一次。
所以：
 a. 外層 loop 最多 n / groupSize 次
 b. 每次內層執行 groupSize 次
 c. 每次內層的操作都是 O(log n)
Sol2 hashmap & Min-heap, 一樣先用hashmap儲存所有card數量,
      用priority_queue確保每次從最小值開始拿, 一樣O(nlogn)


*/

#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
  public:
	bool isNStraightHand(vector<int> &hand, int groupSize) {
		map<int, int> card_cnt;
		for (int &h : hand) {
			++card_cnt[h];
		}

		// run until all card has been group
		while (!card_cnt.empty()) {
			// get the minimum card
			int mini_card = card_cnt.begin()->first;

			// check is consecutive or not
			for (int i = 0; i < groupSize; ++i) {
				if (card_cnt[mini_card + i] == 0)
					return false; // not consecutive
				--card_cnt[mini_card + i];
				if (card_cnt[mini_card + i] == 0)
					card_cnt.erase(mini_card + i);
			}
		}
		return true;
	}
};

// Sorting & Hashmap
class Solution {
  public:
	bool isNStraightHand(vector<int> &hand, int groupSize) {
		unordered_map<int, int> card_cnt;
		sort(hand.begin(), hand.end());
		for (int &h : hand)
			++card_cnt[h];

		// 左到右挑group直到挑完
		for (int &card : hand) {
			if (card_cnt[card] == 0)
				continue; // 已經被挑完了
			for (int i = 0; i < groupSize; ++i) {
				if (card_cnt.count(card + i) == 0)
					return false;
				--card_cnt[card + i];
			}
		}
		return true;
	}
};

// Min-heap & hashmap
typedef struct Compared {
	bool operator()(int a, int b) { return a > b; }
} Compared;
class Solution {
  public:
	bool isNStraightHand(vector<int> &hand, int groupSize) {
		unordered_map<int, int> card_cnt;
		priority_queue<int, vector<int>, Compared> mini_card;
		sort(hand.begin(), hand.end());

		for (int &card : hand) {
			++card_cnt[card];
		}

		// min-heap 是用來紀錄min card index的, 如果card 用完就會pop出去
		for (auto &h : card_cnt) {
			mini_card.push(h.first);
		}

		while (!mini_card.empty()) {
			int start_card = mini_card.top();

			// check 是不是consecutive
			for (int i = 0; i < groupSize; ++i) {
				int curr_card = start_card + i;
				if (card_cnt.count(curr_card) == 0)
					return false;
				// check card是否用完, 用完pop min_heap
				if (--card_cnt[curr_card] == 0) {
					mini_card.pop();
				}
			}
		}
		return true;
	}
};
