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
vector<int> inorderTraversal(Node* root) {
	vector<int>ans;
	stack<Node*>st;
	Node* temp = root;

	while (true) {
		// go to the extreme left until a NULL node is found.
		if (temp != NULL) {
			st.push(temp);
			temp = temp->left;
		}
		// if left root node is null
		else {
			if (st.empty())break;
			// retreat back to the previous node if available.(this node is the root node)
			temp = st.top();
			st.pop();

			// push the root node data to the ans vector and move to the right node.
			ans.push_back(temp->data);
			temp = temp->right;
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