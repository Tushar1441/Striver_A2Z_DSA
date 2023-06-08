#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach
void setMatrixZeroes1(vector<vector<int>> &arr) {
	int row = arr.size();
	int col = arr[0].size();

	// Method 1 --> Store all the indexes containing 0's in a pair vector.

	/*
		vector<pair<int, int>>indexes;

		for (int i = 0; i < row * col; i++) {
			if (arr[i / col][i % col] == 0) {
				indexes.push_back(make_pair(i / col, i % col));
			}
		}


		for (auto it : indexes) {

			for (int i = 0; i < row; i++) {
				arr[i][it.second] = 0;
			}
			for (int i = 0; i < col; i++) {
				arr[it.first][i] = 0;
			}
		}

		// TC --> O((row*col) * (row+col)) + O(row*col)
		// SC --> O(m*n) in worst case when all the elements are zeroes.
	*/

	// Method 2--> Flag all the column and row members as -1 except for zeroes.
	for (int i = 0; i < row * col; i++) {
		if (arr[i / col][i % col] == 0) {
			for (int j = 0; j < row; j++) {
				if (arr[j][i % col] != 0)arr[j][i % col] = -1;
			}
			for (int j = 0; j < col; j++) {
				if (arr[i / col][j] != 0)arr[i / col][j] = -1;
			}
		}
	}

	// change all the -1's to 0's
	for (int i = 0; i < row * col; i++) {
		if (arr[i / col][i % col] == -1)arr[i / col][i % col] = 0;
	}

	// TC --> O((row*col)* (row+col)) + O(row*col)
	// SC --> O(1)

}


// Better Approach --> Marking 1 in arrays instead of the original matrix
void setMatrixZeroes(vector<vector<int>> &matrix) {
	int n = matrix.size();
	int m = matrix[0].size();

	vector<int> col(m, 0);
	vector<int> row(n, 0);

	// Traverse the matrix:
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				// mark ith index of row wih 1:
				row[i] = 1;

				// mark jth index of col wih 1:
				col[j] = 1;
			}
		}
	}


	// Finally, mark all (i, j) as 0
	// if row[i] or col[j] is marked with 1.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (row[i] || col[j]) {
				matrix[i][j] = 0;
			}
		}
	}


	// TC --> O(m*n) + O(m*n)
	// SC --> O(m) + O(n)
}


// Optimal Solution --> Removing the extra space used by
// by imagining the first row and column of the matrix as the row and col arrays
// Note --> at matrix[0][0] both the arrays colide , so we can take a variable
// and update the col[0] in that variable.
void setMatrixZeroes(vector<vector<int>> &matrix) {
	int n = matrix.size();
	int m = matrix[0].size();


	// vector<int> col(m, 0); --> matrix[0][..]
	// vector<int> row(n, 0); --> matrix[..][0]

	int col0 = 1; // taking an extra variable for 0th column

	// step 1: Traverse the matrix and
	// mark 1st row & col accordingly:
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {

				// mark ith index row of first column wih 0:(row array)
				matrix[i][0] = 0;

				// mark jth index col of first row wih 0:(column array)
				if (j != 0) {
					matrix[0][j] = 0;
				}
				else col0 = 0;

			}
		}
	}

	// Step 2: Convert all the elements except the row array and the column array
	// Mark with 0 from (1,1) to (n, m):
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (matrix[i][j] != 0) {
				// check for col & row:
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}
	}

	//step 3: Finally mark the 1st col & then 1st row:
	if (matrix[0][0] == 0) {
		for (int j = 0; j < m; j++) {
			matrix[0][j] = 0;
		}
	}
	// if the col variable is marked 0 then convert the first col to 0's
	if (col0 == 0) {
		for (int i = 0; i < n; i++) {
			matrix[i][0] = 0;
		}
	}


	// TC --> O(m*n) + O(m*n)
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

	setMatrixZeroes(arr);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}

		cout << endl;
	}

}