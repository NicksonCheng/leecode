// proficient
/*
遇到curr_num > 0不斷push到stack, 直到遇到curr_num < 0就將stack
pop出來直到stack.top() > curr_num, 重複直到asteroids走完,
剩下的stack就是剩下的asteroids
*/
class Solution {
  public:
	vector<int> asteroidCollision(vector<int> &asteroids) {
		vector<int> asteroids_stack;
		for (int i = 0; i < asteroids.size(); ++i) {
			int cur_aster = asteroids[i];
			if (cur_aster > 0) {
				asteroids_stack.push_back(cur_aster);
			} else {
				bool win = true;
				while (asteroids_stack.size() > 0) {
					int size = asteroids_stack.size();
					int opposite_aster = asteroids_stack[size - 1];
					if (opposite_aster < 0) {
						// same direction
						break;
					}
					if (opposite_aster >= abs(cur_aster)) {

						// 相撞的要抵銷
						if (opposite_aster == abs(cur_aster))
							asteroids_stack.pop_back();
						win = false;
						break;
					} else
						asteroids_stack.pop_back();
				}
				if (win)
					asteroids_stack.push_back(cur_aster);
			}
		}
		return asteroids_stack;
	}
};