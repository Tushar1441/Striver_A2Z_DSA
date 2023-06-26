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


// using Set data structure
Node* detectCycle(Node* head) {

	unordred_set<Node*>st;

	while (head) {
		if (st.find(head) != st.end()) {
			return head;
		}

		st.insert(head);
		head = head->next;
	}

	return NULL;

	// TC --> O(n);
	// SC --> O(n);
}


// using slow and fast pointers
// move slow by one node and move fast by two nodes.
// If a cycle exists in the ll, they are bound to meet at a certain node.
bool isLoop(Node* head) {
	if (head == NULL || head->next == NULL)return false;

	Node* slow = head;
	Node* fast = head;

	while (fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;

		if (slow == fast)return true;
	}

	return false;

	// TC --> O(n)
	// SC --> O(1)
}


// To return the node also
Node* detectCycle1(Node* head) {

	if (head == NULL || head->next == NULL)return NULL;

	// Make three pointers
	Node* slow = head;
	Node* fast = head;
	Node* entry = head;

	// move the fast and slow pointers by 2 and 1 steps respectively
	while (fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;

		// if both pointers collide then break out of the loop.(it means a cycle exist)
		if (slow == fast)
		{
			// Move the entry pointer and the slow pointer simultaneously.
			// Their collision point will be the starting point of the cycle.
			while (slow != entry)
			{
				slow = slow->next;
				entry = entry->next;
			}
			return entry;
		}
	}

	return NULL;
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



}