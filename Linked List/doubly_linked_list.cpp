#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;


	Node(int val) {
		this->data = val;
		this->next = NULL;
		this->prev = NULL;
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
	head->prev = temp;
	head = temp;
}

void insertAtPosition(Node* head, int val, int position) {
	Node* temp = head;
	int curr_pos = 1;

	while (curr_pos != position) {
		curr_pos++;
		temp = temp->next;
	}

	if (temp->next == NULL) {

	}


	// create a new Node
	Node* new_node = new Node(val);

	// connect the temp node to new_node and the new_node to temp->next node.
	new_node->next = temp->next;
	temp->next->prev = new_node;
	temp->next = new_node;
	new_node->prev = temp;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	Node* node1 = new Node(4);
	insertAtHead(node1, 5);
	insertAtHead(node1, 2);
	print(node1);

	Node* node2 = new Node(4);
	insertAtHead(node2, 5);
	insertAtHead(node2, 2);
	print(node2);

	Node* node3 = addTwoNumbers(node1, node2);
	print(node3);

}