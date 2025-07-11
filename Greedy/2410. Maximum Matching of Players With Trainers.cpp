/*
    greedy, players high 先match
*/
class Solution {
  public:
	int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers) {
		int match = 0;
		sort(players.begin(), players.end(), greater<int>());
		sort(trainers.begin(), trainers.end(), greater<int>());
		int j = 0;
		for (int p : players) {
			if (j < trainers.size() && trainers[j] >= p) {
				++match;
				++j;
			}
		}
		return match;
	}
};