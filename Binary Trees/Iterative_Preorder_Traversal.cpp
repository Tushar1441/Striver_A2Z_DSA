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

// Iteratively, the preOrder traversal can be done using stack ds.
vector<int> preorderTraversal(Node* root) {
	vector<int>ans;
	if (root == NULL)return ans;

	stack<Node*>st;
	st.push(root);

	while (!st.empty()) {
		Node* temp = st.top();
		st.pop();

		if (temp->right)st.push(temp->right);
		if (temp->left)st.push(temp->left);

		ans.push_back(temp->data);
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