#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int val) {
		this->data = val;
		this->left = this->right = NULL;
	}
};


// Using two stacks.
vector<int> postOrderTraversal(Node* root) {
	vector<int>ans;
	if (root == NULL)return ans;

	stack<Node*>st1, st2;
	st1.push(root);

	while (!st1.empty()) {
		root = st1.top();
		st1.pop();

		// push the root value into another stack.
		st2.push(root);

		// and move to left and right node respectively.
		if (root->left)st1.push(root->left);
		if (root->right)st1.push(root->right);
	}

	// push the second stack data to traversal array.
	while (!st2.empty()) {
		ans.push_back(st2.top()->data);
		st2.pop();
	}

	return ans;
}


// Using One Stack
vector<int> postOrderTraversal1(Node* root) {
	vector<int>ans;
	if (root == NULL)return ans;

	stack<Node*>st;

	while (root != NULL || !st.empty()) {
		// go to extreme left possible
		if (root != NULL) {
			st.push(root);
			root = root->left;
		}
		// if root is NULL
		else {
			//retreat back to the previous root node and move to its right
			Node* temp = st.top()->right;

			//if right node is also NULL, move to its root node
			if (temp == NULL) {
				temp = st.top();
				st.pop();

				ans.push_back(temp->data);

				while (!st.empty() && temp == st.top()->right) {
					temp = st.top();
					st.pop();
					ans.push_back(temp->data);
				}
			}

			else root = temp;

		}
	}

	return ans;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif

	Node* node1 = new Node(5);
	node1->left = new Node(6);
	node1->right = new Node(7);

}