#include <bits/stdc++.h>
using namespace std;


// In this approach, we will be using four loops to print all four sides of the matrix.
// 1st loop: This will print the elements from left to right.
// 2nd loop: This will print the elements from top to bottom.
// 3rd loop: This will print the elements from right to left.
// 4th loop: This will print the elements from bottom to top.
void printSpiral(vector<vector<int>> &matrix) {
	int n = matrix.size();
	int m = matrix[0].size();

	// Initialize the pointers reqd for traversal.
	int top = 0, left = 0, bottom = n - 1, right = m - 1;

	// Loop until all elements are not traversed.
	while (top <= bottom && left <= right) {

		// For moving left to right
		for (int i = left; i <= right; i++)
			cout << matrix[top][i] << " ";

		top++;

		// For moving top to bottom.
		for (int i = top; i <= bottom; i++)
			cout << (matrix[i][right]) << " ";

		right--;

		// For moving right to left.
		if (top <= bottom) {
			for (int i = right; i >= left; i--)
				cout << matrix[bottom][i] << " ";

			bottom--;
		}

		// For moving bottom to top.
		if (left <= right) {
			for (int i = bottom; i >= top; i--)
				cout << (matrix[i][left]) << " ";

			left++;
		}
	}

	// TC --> O(n*m)
	// SC --> O(1)
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, m, temp;
	cin >> n >> m ;
	vector<vector<int>> arr;
	for (int i = 0; i < n; i++) {
		vector<int>row;
		for (int i = 0; i < m; i++) {
			cin >> temp;
			row.push_back(temp);
		}

		arr.push_back(row);
	}

	printSpiral(arr);

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << arr[i][j] << " ";
	// 	}

	// 	cout << endl;
	// }

}