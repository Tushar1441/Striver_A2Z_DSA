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


// Brute Force Approach --> Put a pointer on a node in NodeA
// and check if the equal node is present in NodeB
Node* getIntersectionNode(Node* headA, Node* headB) {
	Node* temp = headA;

	while (temp) { // pick a node in NodeA

		Node* temp1 = headB;
		// compare with all the elements in NodeB
		while (temp1) {
			if (temp == temp1)return temp;
			temp1 = temp1->next;
		}

		temp = temp->next;
	}

	return NULL;
}


// USing Hashset --> store all the nodes of ll-A
// and traverse through ll-B and check for equal node in the set.
Node* getIntersectionNode1(Node* headA, Node* headB) {
	set<Node>st;
	Node* temp = headA;
	while (temp) {
		st.insert(temp);
		temp = temp->next;
	}

	// now set has stored all the nodes of ll-A.

	Node* temp1 = headB;
	while (temp1) {
		if (st.find(temp1) != st.end())return temp1;
		temp1 = temp1->next;
	}

	return NULL;

	// TC --> O(n + m)
	// SC --> O(n)
}


// Optimal Approach --> Using two pointers
Node* getIntersectionNode(Node* headA, Node* headB) {
	if (headA == NULL || headB == NULL)return NULL;

	Node* temp1 = headA;
	Node* temp2 = headB;

	while (temp1 != temp2) {

		temp1 = temp1 == NULL ? headB : temp1->next;
		temp2 = temp2 == NULL ? headA : temp2->next;
	}

	return temp1;
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