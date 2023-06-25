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

void deleteAtHead(Node* &head) {
	Node* temp = head;
	head = head->next;
	free(temp);
}

void deleteAtKthPosition(Node* &head, int pos) {
	if (pos == 0) {
		deleteAtHead(head);
		return;
	}

	Node* prev = head;
	int curr_pos = 0;

	while (curr_pos != pos - 1) {
		prev = prev->next;
		curr_pos++;
	}

	Node* curr = prev->next;
	prev->next = prev->next->next;
	free(curr);
}

//iterative
int lengthOfLL(Node* head) {
	int length  = 0;
	Node* temp = head;

	while (temp != NULL) {
		length++;
		temp = temp->next;
	}

	return length;
}


//recursive
int lengthOfLLRecursive(Node* head) {
	if (head == NULL)return 0;

	return lengthOfLLRecursive(head->next) + 1;
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
	deleteAtHead(node1);
	print(node1);
	insertAtTail(node1, 7);
	print(node1);
	cout << lengthOfLL(node1) << endl;
	insertAtKthPosition(node1, 8, 2);
	print(node1);
	cout << lengthOfLLRecursive(node1) << endl;

	// deleteAtKthPosition(node1, 2);
	// print(node1);
}