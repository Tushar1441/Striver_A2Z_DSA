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


// Brute Force Approach --> Store all the elements in a vector
// and then check the vector elements
isPalindrome(Node* head) {
	if (head == NULL || head->next == NULL)return true;

	Node* temp = head;
	vector<int>arr;
	while (temp != NULL) {
		arr.push_back(temp->data);
		temp = temp->next;
	}

	int n = arr.size();
	for (int i = 0; i < n / 2; i++) {
		if (arr[i] != arr[n - 1 - i])return false;
	}

	return true;
}


Node* reverseLL(Node* head) {
	Node* prev = NULL;
	Node* forward = NULL;

	while (head) {
		forward = head->next;
		head->next = prev;
		prev = head;
		head = forward;
	}
	return prev;
}

//Optimal Approach -->
// Step1) Traverse till the middle element using slow and fast pointer approach.
// Step2) Reverse the other half of the linked list.
// Step3)Comapre the first half and the second half using two pointers.
isPalindrome1(Node* head) {
	if (head == NULL || head->next == NULL)return true;

	Node* slow = head;
	Node* fast = head;

	// find the middle element
	while (fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	slow->next = reverseLL(slow->next);
	slow = slow->next;

	while (slow != NULL) {
		if (head->data != slow->data)return false;
		head = head->next;
		slow = slow->next;
	}

	return true;
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
	// insertAtHead(node1, 4);
	insertAtHead(node1, 5);
	insertAtHead(node1, 6);
	print(node1);


	cout << isPalindrome(node1);

}