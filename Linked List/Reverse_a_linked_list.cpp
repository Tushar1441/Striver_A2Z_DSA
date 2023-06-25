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

// iterative way
Node* reverseLL(Node* head) {
	// if ll contains zero or one element, return the ll.
	if (head == NULL || head->next == NULL)return head;

	Node* prev = NULL;

	while (head) {
		// store the next node
		Node* next_node = head->next;

		// reverse the current node
		head->next = prev;

		//move all the pointers by one step
		prev = head;
		head = next_node;
	}

	// at the end, prev pointer will be pointing to the last node of the linked list
	return prev;
}


// recursive Way
Node* reverseLLRecursive(Node* head) {
	if (head->next == NULL || head == NULL)return head;

	Node* new_head = reverseLL(head->next);
	head->next->next = head;
	head->next = NULL;
	return new_head;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	Node* node1 = new Node(6);
	insertAtHead(node1, 5);
	insertAtHead(node1, 4);
	insertAtHead(node1, 3);
	insertAtHead(node1, 2);
	insertAtHead(node1, 1);
	print(node1);

	Node* node2 = reverseLLRecursive(node1);
	print(node2);

}