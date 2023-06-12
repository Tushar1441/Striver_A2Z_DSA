#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r) {
	// To calculate nCr, there are two methods:-

	// 1) By using brute force approach --> nCr - n!/(r! * (n-r)!)
	// Just run a loop for every requirement. till n,n-r,r.
	// TC --> O(n) + O(r) + O(n-r)


	// 2) Optimal Approach -->
	long long res = 1;

	for (int i = 0; i < r; i++) {
		res = res * (n - i);
		res = res / (i + 1);
	}

	return res;
	// TC --> O(r)


}

// Element in Pascal's triangle by column and row.
int elementInPascalTriangle(int row, int col) {
	// We can extract the element simply by storing the complete Pascal's triangle
	// and then pick the element by it's row and col number.

	// If we carefully observe, the element at r(row) and c(col) index in a pascal's
	// triangle is nothing but rCc (nCr).

	int ans = nCr(row - 1, col - 1);
	return ans;

	// TC --> O(col - 1 );
}



// Printing nth row in the pascal's Triangle


// Method-1 --> Brute Force Approach
// A nth row in pascal triangle contains n elements.
// so, run a loop for n times and calculate the col elements by doing (n-1)C(r-1).
vector<int> nthRowInPascalTriangle1(int n) {
	vector<int> ans;
	for (int col = 1; col <= n; col++) {
		int num = nCr(n - 1, col - 1);
		ans.push_back(num);
	}

	return ans;
	// TC --> O(n * r)
}



// Method 2 --> Optimal Approach
vector<int> nthRowInPascalTriangle(int n) {

	vector<int> ans;
	ans.push_back(1);
	int temp = 1;
	for (int i = 1; i < n; i++) {
		temp *= (n - i);
		temp /= (i);
		ans.push_back(temp);
	}

	return ans;

	// TC --> O(n);
	// SC --> O(1)  no extra space required other than the ans space.

}


// Printing the complete pascal's triangle.
// Method 1 --> Generate all the index elements by using nCr property.
vector<vector<int>> printPascalTriangle(int numRows) {
	vector<vector<int>> ans;

	for (int i = 0; i < numRows; i++) {
		vector<int>temp;
		for (int j = 0; j <= i; j++) {
			temp.push_back(nCr(i, j));
		}

		ans.push_back(temp);
	}
	return ans;

	// TC --> O(n*n*j) -- o(n^3)
	// SC --> O(n)
}


// Method 2 --> Generate all the rows by using the efficient method.
vector<vector<int>> printPascalTriangle2(int numRows) {
	vector<vector<int>> ans;

	for (int i = 1; i <= numRows; i++) {
		ans.push_back(nthRowInPascalTriangle(i));
	}

	return ans;
	// TC --> O(n^2)
}



// Method 3 --> If we carefully observe the pattern, leaving the 0th col index and the nth
// col index, all the index elements are (row-1[i-1] + row-1[i]).
vector<vector<int>> printPascalTriangle3(int numRows) {
	vector<vector<int>> ans;
	for (int i = 0; i < numRows; i++) {
		vector<int>temp;
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)temp.push_back(1); // first and last element of any row will be 1.
			else {
				int x = ans[i - 1][j - 1] + ans[i - 1][j];
				temp.push_back(x);
			}
		}

		ans.push_back(temp);
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
	int n;
	cin >> n;
	vector<vector<int>> ans = printPascalTriangle(n);
	// vector<int> ans1 = nthRowInPascalTriangle(3);
	// for (auto it : ans1) {
	// 	cout << it << " ";
	// } cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	// cout << elementInPascalTriangle(6, 3) << endl;
}