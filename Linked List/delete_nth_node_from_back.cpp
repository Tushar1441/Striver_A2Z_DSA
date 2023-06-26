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
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

void insertAtHead(Node* &head, int val) {
	Node* temp = new Node(val);
	temp->next = head;
	head = temp;
}


// Brute force Approach
// First calculate the total length of the ll.
// Then calulate the pos of the node to be deleted from the front
// by doing totalLength - pos.
Node* deleteNthNodeFromBack(Node* head, int pos) {
	int length = 0;

	// First calculate the total length of the ll.
	Node* temp = head;
	while (temp) {
		length++;
		temp = temp->next;
	}

	// Then calulate the pos of the node to be deleted from the front
	int frontPos = length - pos;

	// Delete the element at frontPos from the start
	if (frontPos < 0)return head;

	if (frontPos == 0) {
		Node* temp = head;
		head = head->next;
		free(temp);
		return head;
	}

	int curr_pos = 1;
	Node* prev = head;

	while (curr_pos != frontPos) {
		prev = prev->next;
		curr_pos++;
	}

	Node* curr = prev->next;
	prev->next = prev->next->next;
	free(prev);

	return head;

	// TC --> O(N) + O(N)
	// SC --> O(1)
}


// Optimal Approach --> Using two pointers
Node* deleteNthNodeFromBack1(Node* head, int pos) {

	// make a dummy node pointing to head.
	Node* start = new Node(5);
	start->next = head;
	// make a temp node to traverse from the dummy node.
	Node* slow = start;

	// make another node pointing to head.
	Node* fast = head;

	// Move the fast pointer to pos given in the statement(from the front).
	for (int i = 0; i < n; i++) {
		fast = fast->next;
	}

	// Now the remaining nodes will be --> length of ll - pos
	// this is nothing but the frontPos we were calculating in the brute force approach
	// to get the total Length, just move both the pointers at same time till the fast
	// pointer reaches NULL.

	while (fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}


	// delete the node next to the slow pointer
	slow->next = slow->next->next;

	return start->next;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	Node* node1 = new Node(5);
	insertAtHead(node1, 4);
	insertAtHead(node1, 3);
	insertAtHead(node1, 2);
	insertAtHead(node1, 1);
	// insertAtHead(node1, 1);
	print(node1);

}