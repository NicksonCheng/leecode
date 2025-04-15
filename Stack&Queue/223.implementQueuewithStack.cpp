// hint
/*
    1. 直接兩個stack, 一個是input(push)用的, 一個是output(pop)用的
       類似兩桶互倒的感覺, 如果push的時候output stack有element先把它倒回input
   stack, 再push, pop的時候反之

*/
class MyQueue {
  public:
	stack<int> input_s;
	stack<int> output_s;
	MyQueue() {}

	void push(int x) {
		//
		while (!output_s.empty()) {
			int item = output_s.top();
			output_s.pop();
			input_s.push(item);
		}
		input_s.push(x);
	}

	int pop() {
		while (!input_s.empty()) {
			int item = input_s.top();
			input_s.pop();
			output_s.push(item);
		}
		int pop_item = output_s.top();
		output_s.pop();
		return pop_item;
	}

	int peek() {
		while (!input_s.empty()) {
			int item = input_s.top();
			input_s.pop();
			output_s.push(item);
		}
		int pop_item = output_s.top();
		return pop_item;
	}

	bool empty() { return input_s.empty() && output_s.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */