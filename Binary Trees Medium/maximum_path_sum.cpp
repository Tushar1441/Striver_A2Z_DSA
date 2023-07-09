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

// ------------------------------------------------------------

int maxSum = 0;

// calculate the max sum as  node-> val + max(left subtree,rigth subtree) for any root node.
int sum(Node* root) {
	if (root == NULL)return 0;

	// don't take any negative value from any subtree because it will surely
	// decrease the sum.
	int leftMax = max(0, sum(root->left));
	int rightMax = max(0, sum(root->right));

	maxSum = max(maxSum, root->val + leftMax + rightMax );

	return root->val + max(leftMax, rightMax);
}


int maxPathSum(Node* root) {
	sum(root);
	return maxSum;
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