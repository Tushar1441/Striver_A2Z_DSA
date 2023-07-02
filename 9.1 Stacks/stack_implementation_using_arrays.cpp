#include <bits/stdc++.h>
using namespace std;

class Stack {
	int top;
	int capacity;
	int* arr;

public:
	Stack(int c) {
		this->capacity = c;
		arr = new int[c];
		this->top = -1;
	}

	void push(int data) {
		if (this->top == this->capacity - 1) {
			cout << "Overflow\n";
			return;
		}
		this->top++;
		arr[this->top] = data;
	}

	int pop() {
		if (this->top == -1) {
			cout << "underflow\n";
			return -1;
		}
		this->top--;
	}

	int getTop() {
		if (this->top == -1) {
			cout << "underflow\n";
			return -1;
		}

		return this->arr[this->top];
	}

	bool isEmpty() {
		return this->top == -1;
	}

	int size() {
		return this->top + 1;
	}

	bool isFull() {
		return this->top == this->capacity - 1;
	}

};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	Stack st(3);

	st.push(1);
	st.push(2);
	cout << st.getTop() << endl;
	st.push(3);
	st.push(4);
	cout << st.getTop() << endl;
	st.pop();
	cout << st.getTop() << endl;
	cout << st.size() << endl;

}