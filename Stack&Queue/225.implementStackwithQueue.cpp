// proficient
/*
    只管pop, push, 內部不需要是stack的長相, 那就pop的時候直接去找最後一個值就好,
    我們用一個pivot去尋找最後一個值然後每次pop都要記得push回去,
   這樣就只需要用到一個queue
*/
class MyStack {
  public:
	queue<int> q;
	MyStack() {}

	void push(int x) { q.push(x); }

	int pop() {
		int pivot = 0;
		q.push(pivot);
		int prev_item = q.front();

		// find last element in queue
		while (q.front() != pivot) {
			prev_item = q.front();
			q.pop();

			// push item back
			if (q.front() != pivot)
				q.push(prev_item);
		}
		// pop pivot
		q.pop();
		return prev_item;
	}

	int top() {
		int pivot = 0;
		q.push(pivot);
		int prev_item = q.front();

		// find last element in queue
		while (q.front() != pivot) {
			prev_item = q.front();
			q.pop();

			// push item back
			q.push(prev_item);
		}
		// pop pivot
		q.pop();
		return prev_item;
	}

	bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */