#include <iostream>
#include <stack>
using namespace std;
/* save stack with currval - min, and keep record minimal value*/
class MinStack {
  public:
	stack<long> min_stack;
	long min_val = 0;
	MinStack() {}

	void push(int val) {
		if (min_stack.empty()) {
			min_stack.push(0);
			min_val = val;
		} else {
			min_stack.push(val - min_val);
			if (val < min_val)
				min_val = val;
		}
	}

	void pop() {
		long top = min_stack.top();
		if (top < 0)
			min_val = min_val - top;
		min_stack.pop();
	}

	int top() {
		long top = min_stack.top();
		return top > 0 ? top + min_val : min_val;
	}

	int getMin() { return min_val; }
	~MinStack() {};
};
int main() {
	MinStack *minStack = new MinStack();
	minStack->push(1);
	minStack->push(2);
	minStack->push(0);
	cout << minStack->getMin() << endl; // return 0
	minStack->pop();
	cout << minStack->top() << endl;    // return 2
	cout << minStack->getMin() << endl; // return 1
}