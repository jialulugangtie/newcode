#include<stack>
#include<iostream>
using namespace std;

class MyQueue {
	void push(int value) {
		stack1.push(value);
	}

	int pop() {
		while (!stack1.empty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}
		int x = stack2.top();
		stack2.pop();
		while (!stack2.empty()) {
			stack1.push(stack2.top());
			stack2.pop();
		}
		return x;
	}

private:
	std::stack<int> stack1;
	std::stack<int> stack2;
};


int main() {


	return 0;
}