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

Node* deleteMiddleElement(Node* head) {
	if (head->next == NULL)return NULL;

	Node* slow = head;
	Node* fast = head;

	// make a dummy node which chases the slow pointer
	// because slow will point to the middle node.
	// and we will need a node prior to that node.
	Node* start = new Node(5);
	start->next = slow;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;

		start = start->next;
	}

	start->next = start->next->next;
	return head;

	// TC --> O(N/2)
	// SC --> O(1)
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	Node* node1 = new Node(6);
	// insertAtHead(node1, 6);
	insertAtHead(node1, 5);
	insertAtHead(node1, 4);
	insertAtHead(node1, 3);
	insertAtHead(node1, 2);
	insertAtHead(node1, 1);
	print(node1);

	Node* node2 = middleElement(node1);
	print(node2);

}