// hint
// important
/*
    kahn's algorithm, 先hashmap計算每個node in-degree,
   in-degree為0的node開始BFS, 每次都push到res vector, 直到queue為空

   2. DFS: 如果不存在cycle, 一定存在一種組合可以走完
*/
class Solution {
  public:
	vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
		vector<vector<int>> graph(numCourses);
		vector<int> in_degree(numCourses, 0);
		vector<int> res;
		queue<int> courses;

		for (auto &p : prerequisites) {
			++in_degree[p[0]];
			graph[p[1]].push_back(p[0]);
		}
		// start from in-degree=0 node
		for (int i = 0; i < in_degree.size(); ++i) {
			if (in_degree[i] == 0)
				courses.push(i);
		}
		int delete_num = 0; // check if all node is deleted(cycle check)
		while (!courses.empty()) {
			int cur_course = courses.front();
			// cur_course in-degree為0就push進res(不會再遇到了)
			if (in_degree[cur_course] == 0) {
				res.push_back(cur_course);
				// delete from in_degree
			}

			// push next course to queue and pop node
			for (int i = 0; i < graph[cur_course].size(); ++i) {
				int next_course = graph[cur_course][i];

				if (--in_degree[next_course] == 0)
					courses.push(next_course);
			}
			courses.pop();
			++delete_num;
		}
		vector<int> empty_res;
		return delete_num == numCourses ? res : empty_res;
	}
};