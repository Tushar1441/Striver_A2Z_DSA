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


Node* addTwoNumbers(Node* l1, Node* l2) {

	Node* dummy = new Node(0);
	Node* temp = dummy;
	int carry = 0;

	while (l1 != NULL && l2 != NULL) {

		int sum = 0;

		if (l1 != NULL) {
			sum += l1->data;
			l1 = l1->next;
		}
		if (l2 != NULL) {
			sum += l2->data;
			l2 = l2->next;
		}
		sum += carry;
		carry = sum / 10;

		Node* new_node = new Node(sum % 10);
		temp->next = new_node;
		temp = temp->next;
	}

	return dummy->next;
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