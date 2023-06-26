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


Node* getMid(Node* head) {
	Node* slow = head;
	Node* fast = head->next;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}


Node* merge(Node* left, Node* right) {

	// make two dummy nodes
	// one to traverse and connect the sorted ll elements
	// and another to store the starting of this dummy node.
	Node* tail = new Node(5);
	Node* dummy = tail;

	// performing the merging operation.
	while (left && right) {
		if (left->data <= right->data) {
			tail->next = left;
			left = left->next;
		}

		else {
			tail->next = right;
			right = right->next;
		}

		tail = tail->next;
	}

	// connect the remaining list to the tail
	// if left list is not exhausted
	if (left) {
		tail->next = left;
	}

	// if right list is not exhausted
	if (right) {
		tail->next = right;
	}

	return dummy->next;
}

Node* sortList(Node* head) {
	if (head == NULL || head->next == NULL)return head;

	Node* left = head;
	// Find the middle node.
	// for even number of elements e.g = n ==4 --> mid will be 2.
	Node* right = getMid(head);

	// we are calculating mid before one pos so that we can make it point to null.
	// and divide it into two parts.
	// store the next before making it point to NULL.
	Node* temp = right->next;
	right->next = NULL;
	// move the right by one position.
	right = temp;

	// now left denotes the starting of first half of the ll.
	// and right denotes the starting of the second half of the ll.

	// now call the mergesort on the left half and the right half.
	left = sortList(left);
	right = sortList(right);

	// merge the left and rigth half

	return merge(left, right);

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	Node* node1 = new Node(4);
	// insertAtHead(node1, 6);
	insertAtHead(node1, 5);
	insertAtHead(node1, 2);
	insertAtHead(node1, 9);
	insertAtHead(node1, 7);
	insertAtHead(node1, 1);
	print(node1);

	Node* node2 = sortList(node1);
	print(node2);

}