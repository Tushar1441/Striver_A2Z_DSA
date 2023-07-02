#include <bits/stdc++.h>
using namespace std;


class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};


class Stack {
	Node* head;
	int capacity;
	int currSize;

public:
	Stack(int c) {
		this->capacity = c;
		this->currSize = 0;
		head = NULL;
	}

	bool isEmpty() {
		return this->head = NULL;
	}

	bool isFull() {
		return this->capacity == this->currSize;
	}

	void push(int data) {
		if (this->currSize == this->capacity) {
			cout << "Overflow\n";
			return;
		}
		Node* new_node = new Node(data);
		new_node->next = head;
		this->head = new_node;
		this->currSize++;
	}

	int pop() {
		if (this->head == NULL) {
			cout << "Underflow\n";
			return INT_MIN;
		}

		Node* new_head = this->head->next;
		this->head->next = NULL;

		Node* tobeRemoved = this->head;
		int result = tobeRemoved->data;

		delete tobeRemoved;
		this->head = new_head;

		return result;
	}

	int getTop() {
		if (this->head == NULL) {
			cout << "Underflow\n";
			return INT_MIN;
		}
		return this->head->data;
	}

	int size() {
		return this->currSize;
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