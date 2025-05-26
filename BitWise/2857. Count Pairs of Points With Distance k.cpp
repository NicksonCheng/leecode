// 注意要用2-D hashtable而不是pair作為key(這樣很怪)
/*
    1. brutal force, 直接計算每個pair distance, O(n^2)

    2. two sum 進階版 two hashmap, 一個for x, 一個for y, 每個corrdinates都去xor
   潛在x2, y2(x2 = x1 ^ x, y2 = y1 ^ y), pair 可能 (0,k), (1, k - 1), (2, k-2),
   後面再去match 這個pair

        要注意, 是把自己(x1,y1)加入hashtable
        而不是去搜尋潛在的pair加入hashtable(這樣會比較慢因為hashtable太多pair)

        time complexity O(kn), space: O(n)
*/
class Solution {
  public:
	int countPairs(vector<vector<int>> &coordinates, int k) {
		unordered_map<int, unordered_map<int, int>> hm;
		int res = 0;
		for (int i = 0; i < coordinates.size(); ++i) {
			int x1 = coordinates[i][0];
			int y1 = coordinates[i][1];
			// try all potential pairs, if pair exist in hashtable, add it to
			// res
			for (int j = 0; j <= k; ++j) {
				int x = j, y = k - j;
				int x2 = x1 ^ x;
				int y2 = y1 ^ y;
				if (hm.count(x2) > 0 && hm[x2].count(y2) > 0) {
					res += hm[x2][y2];
				}
			}
			++hm[x1][y1]; // 可能xor自己就是答案所以不能先加入
		}
		return res;
	}
};