#include <bits/stdc++.h>
using namespace std;


// Brute Force --> Make an answer matrix and put all the matrix elements onto their
// rotated position in the answer matrix
vector<vector<int>> rotateMatrix1(vector<vector<int>> &matrix) {
	int n = matrix.size();
	vector<vector<int>> ans(n, vector<int> (n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[j][n - i - 1] = matrix[i][j];
		}
	}

	return ans;

	// TC --> O(n^2)
	// SC --> O(n^2) -- making an answer matrix of size n*n
}



// Optimal Solution --> We will do the rotating in place
// By doing some observation we can find that
// if we transpose the matrix and then reverse every row, we get the rotated matrix
void rotateMatrix(vector<vector<int>> &matrix) {
	int n = matrix.size();

	// Step 1 -- Transposing the matrix(converting rows to columns and vice versa)
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}

	// Step 2 -- Reversing every row
	for (int i = 0; i < n; i++) {
		reverse(matrix[i].begin(), matrix[i].end());
	}

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

	rotateMatrix(arr);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}

		cout << endl;
	}

}