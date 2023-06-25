#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;


	Node(int val) {
		this->data = val;
		this->next = NULL;
	}
};

void print(Node* head) {

	Node* temp = head;

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void insertAtHead(Node* &head, int val) {
	Node* temp = new Node(val);
	temp->next = head;
	head = temp;
}

void insertAtTail(Node* &head, int val) {
	Node* temp = new Node(val);

	Node* temp1 = head;
	while (temp1->next != NULL) {
		temp1 = temp1->next;
	}

	temp1->next = temp;
}


void insertAtKthPosition(Node* &head, int val, int pos) {
	if (pos == 0) {
		insertAtHead(head, val);
		return;
	}

	Node* temp = head;

	while (pos != 1) {
		temp = temp->next;
		pos--;
	}

	Node* new_node = new Node(val);
	new_node-> next = temp->next;
	temp->next = new_node;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	Node* node1 = new Node(5);
	print(node1);
	insertAtHead(node1, 6);
	print(node1);
	insertAtTail(node1, 7);
	print(node1);
	insertAtKthPosition(node1, 8, 2);
	print(node1);

}