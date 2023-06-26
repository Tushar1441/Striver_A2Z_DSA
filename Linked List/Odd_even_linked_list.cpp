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


// trverse the linked list using two pointers
// one at the odd indexes and other at the even indexes.
// update the odd node to even->next node and even node to odd->next node.
Node* groupOddEven(Node* head) {
	if (head == NULL || head->next == NULL || head->next->next == NULL)return head;

	Node* odd = head;
	Node* even = head->next;
	Node* even_start = even;

	while (odd->next != NULL && even->next != NULL ) {

		//connect the odd node to next odd node
		odd->next = even->next;
		// move the odd to even->next or the next odd node
		odd = odd->next;

		//connect the even node to next even node
		even->next = odd->next;
		// move the even to odd->next or the next even node
		even = even->next;
	}



	// Connect the last odd index to the first even index.
	odd->next = even_start;

	// if not pointed already, point the last even node to NULL.
	if (even != NULL)even->next = NULL;

	return head;

	// TC --> O(N)
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

	Node* node2 =  groupOddEven(node1);
	print(node2);

}