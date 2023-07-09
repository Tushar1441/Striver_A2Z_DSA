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


vector<int> preInPostOrderTraversals(Node* root) {
	// initialise a pair stack
	stack<pair<Node*, int>>st;

	st.push({root, 1});
	vector<int>pre, in, post;

	if (root == NULL)return;

	while (!st.empty()) {
		auto it = st.top();
		st.pop();

		// if number associated with node is 1, then it belongs to preorder traversal
		// store it in the pre array and increment the number and again push it into the stack
		if (it.second == 1) {
			pre.push_back(it.first->data);
			it.second++;
			st.push(it);

			// move to the left
			if (it.first->left != NULL) {
				st.push({it.first->left, 1});
			}
		}

		else if (it.second == 2) {
			in.push_back(it.first->data);
			it.second++;
			st.push(it);

			// move to the right
			if (it.first->right != NULL) {
				st.push({it.first->right, 1});
			}
		}

		// if num == 3
		else {
			post.push_back(it.first->val);
		}
	}


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