/*
    1. hashtable time: O(n), space O(n)

    2. star 必定每條edge都會出現, O(1), O(1)
*/
class Solution {
  public:
	int findCenter(vector<vector<int>> &edges) {
		int cand_1 = edges[0][0];
		int cand_2 = edges[0][1];
		int star;
		if (cand_1 == edges[1][0] || cand_1 == edges[1][1])
			star = cand_1;
		else
			star = cand_2;
		return star;
	}
};