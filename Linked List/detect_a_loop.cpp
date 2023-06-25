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

bool isLoop(Node* head) {
	if (head == NULL || head->next == NULL)return false;

	Node* slow = head;
	Node* fast = head;

	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;

		if (slow == fast)return true;
	}

	return false;
}

Node* detectCycle(Node* head) {
	unordred_set<Node*>st;

	while (head) {
		if (st.find(head) != st.end()) {
			return head;
		}

		st.insert(head);
		head = head->next;
	}

	return false;
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