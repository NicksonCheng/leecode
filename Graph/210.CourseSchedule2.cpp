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

/*
    DFS: 每堂課都走走看, 走到重複的課程代表無法修完
    注意: 後續課程必須先上完才能push這個課程, 然後最後才reverse, 不然會亂掉
    ex: 0->1->3    如果先dfs 0->1->3, 2課程就會到最後才上課, 這樣是不行的
        0->2->3
*/
class Solution {
  public:
	vector<int> res;
	vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
		// course has been taken or not
		vector<bool> visit(numCourses, false);
		vector<vector<int>> graph(numCourses);
		unordered_set<int> topology;
		bool can_schedule = true;
		// create course graph
		for (int i = 0; i < prerequisites.size(); ++i) {
			int pre_course = prerequisites[i][1];
			int post_course = prerequisites[i][0];
			graph[pre_course].push_back(post_course);
		}
		for (int i = 0; i < numCourses; ++i) {
			can_schedule = can_schedule && dfs(graph, visit, topology, i);
		}
		reverse(res.begin(), res.end());
		if (!can_schedule)
			return {};
		else
			return res; // 因為是從後面課程push回來, 記得要reverse
	}
	bool dfs(vector<vector<int>> &graph, vector<bool> &visit,
	         unordered_set<int> &topology, int cur_course) {
		if (visit[cur_course])
			return true;
		if (topology.find(cur_course) != topology.end()) {
			return false;
		}
		// cout<< cur_course<<endl;
		//  insert in topology

		topology.insert(cur_course);
		// walk to next course
		for (int i = 0; i < graph[cur_course].size(); ++i) {

			if (!dfs(graph, visit, topology, graph[cur_course][i]))
				return false;
		}

		// 後續課程完成後才push這個課程
		res.push_back(cur_course);
		// sign visit in current course
		visit[cur_course] = true;
		return true;
	}
};