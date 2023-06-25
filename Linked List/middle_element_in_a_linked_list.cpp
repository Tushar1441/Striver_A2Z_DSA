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


Node* middleElement(Node* head) {
	Node* temp = head;

	// first find the total length of the ll
	int length = 0;
	while (temp != NULL) {
		++length;
		temp = temp->next;
	}

	int counter = 0;
	while (counter <= length / 2) {
		if (counter == length / 2) {
			return head;
		}

		head = head->next;
		++counter;
	}

	return NULL;

	//TC --> O(n + n/2);
}



Node* middleNode(ListNode* head) {
	Node *slow = head, *fast = head;
	while (fast && fast->next)
		slow = slow->next, fast = fast->next->next;
	return slow;

	// TC --> O(n)
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