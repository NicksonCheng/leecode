// solution
/* two pass, 紀錄每個domino的力量, 最後看力量傾向哪邊. 力量隨距離遞減*/
class Solution {
  public:
	string pushDominoes(string dominoes) {
		int n = dominoes.length();
		vector<int> forces(n, 0);

		int force = 0;
		for (int i = 0; i < n; ++i) {
			if (dominoes[i] == 'R')
				force = n;
			else if (dominoes[i] == 'L')
				force = 0;
			else
				force = max(force - 1, 0);

			forces[i] += force;
		}

		// right to left
		force = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (dominoes[i] == 'L')
				force = n;
			else if (dominoes[i] == 'R')
				force = 0;
			else
				force = max(force - 1, 0);

			forces[i] -= force;
		}
		string res;
		for (int i = 0; i < forces.size(); ++i) {
			if (forces[i] > 0)
				res.push_back('R');
			else if (forces[i] < 0)
				res.push_back('L');
			else
				res.push_back('.');
		}
		return res;
	}
};