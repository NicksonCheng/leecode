/*
    1. sort every time in findMedian and traverse the midian -> O(nlogn)
    2. 將array 切兩半, 左邊為max_heap, 右邊為min_heap,
        勁量維持兩邊平衡, left <= right.size(),
   find的時候用各自的top去計算(根據size決定取右邊還是兩邊平均)
*/
class MedianFinder {
  public:
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<>> min_heap;
	MedianFinder() {}

	void addNum(int num) {
		if (min_heap.empty()) {
			min_heap.push(num);
			return;
		}
		if (num > min_heap.top())
			min_heap.push(num);
		else
			max_heap.push(num);

		// right 可以接受比 left 多一個(odd 時 top就是median)
		if (max_heap.size() + 1 < min_heap.size()) {
			max_heap.push(min_heap.top());
			min_heap.pop();
		}
		// left 不可以比right大, 要維持平衡
		else if (min_heap.size() < max_heap.size()) {
			min_heap.push(max_heap.top());
			max_heap.pop();
		}
	}

	double findMedian() {
		if (max_heap.size() == min_heap.size())
			return (double)(max_heap.top() + min_heap.top()) / 2.0;
		else {
			// 右邊的 min_heap第一個為中位數
			return (double)min_heap.top();
		}
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */