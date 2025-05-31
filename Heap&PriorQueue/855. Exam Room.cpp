/*
    set 儲存排序好的入座順序, check 每個人的interval distance決定下一次要插哪裡
    O(k)
    leave 直接移除 O(logk), red black tree


    sol2. heap 插入interval
    seat time complexity O(logk)
*/
class ExamRoom {
  public:
	set<int> occupy;
	int n;
	ExamRoom(int n) { this->n = n; }

	int seat() {
		int target_seat = -1;
		if (occupy.empty())
			target_seat = 0;
		else {
			int prev = 0;
			int max_dis = 0;

			// 檢查head
			int dis = *occupy.begin();
			if (dis > max_dis) {
				max_dis = dis;
				target_seat = 0;
			}
			for (auto &cur : occupy) {
				dis = (cur - prev) / 2;
				if (dis > max_dis) {
					max_dis = dis;
					target_seat = prev + dis;
				}
				prev = cur;
			}
			// tail 也要檢查
			// cout << prev << endl;
			dis = (n - prev - 1);
			if (dis > max_dis) {
				target_seat = prev + dis;
			}
		}
		occupy.insert(target_seat);
		return target_seat;
	}

	void leave(int p) { occupy.erase(p); }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

#include <queue>
#include <set>
#include <unordered_map>
using namespace std;

struct Interval {
	int start;
	int end;

	static int N;

	int getDist() const {
		if (start == -1)
			return end;
		if (end == N)
			return N - 1 - start;
		return (end - start) / 2;
	}

	bool operator<(const Interval &other) const {
		int d1 = this->getDist();
		int d2 = other.getDist();
		if (d1 == d2)
			return start > other.start; // 最小 index 優先
		return d1 < d2;                 // 最大距離優先
	}
};

int Interval::N = 0;

class ExamRoom {
	int N;
	priority_queue<Interval> pq;
	set<int> students;                                   // 快速判斷誰入座了
	unordered_map<int, int> leftNeighbor, rightNeighbor; // 鄰居座位追蹤

  public:
	ExamRoom(int n) {
		N = n;
		Interval::N = n;
		pq.push({-1, n});
	}

	int seat() {
		while (!pq.empty()) {
			Interval interval = pq.top();
			pq.pop();

			int start = interval.start;
			int end = interval.end;

			// 驗證這區間是否還有效（可能已被分割）
			if (start != -1 && students.count(start) == 0)
				continue;
			if (end != N && students.count(end) == 0)
				continue;

			int seat;
			if (start == -1)
				seat = 0;
			else if (end == N)
				seat = N - 1;
			else
				seat = (start + end) / 2;

			// 加入座位
			students.insert(seat);

			// 建立新的空區間
			pq.push({start, seat});
			pq.push({seat, end});

			leftNeighbor[seat] = start;
			rightNeighbor[seat] = end;

			return seat;
		}

		return -1; // 不應該到這裡
	}

	void leave(int p) {
		students.erase(p);

		int left = leftNeighbor[p];
		int right = rightNeighbor[p];

		pq.push({left, right});

		// 更新鄰居
		if (left != -1)
			rightNeighbor[left] = right;
		if (right != N)
			leftNeighbor[right] = left;
	}
};
