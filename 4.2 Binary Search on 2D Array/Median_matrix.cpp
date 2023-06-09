#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach -->
// step 1 --> Create a temp array with n*m size and fill all the elements of the matrix into the array
// step 2 -->sort the array
// step --> return the median
int matrixMedian1(vector<vector<int>> &matrix) {
	int row = matrix.size();
	int col = matrix[0].size();

	vector<int>arr;

	// Filling the array
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr.push_back(matrix[i][j]);
		}
	}

	//  sorting the array
	sort(arr.begin(), arr.end());

	// return the median
	return (arr[arr.size() / 2]);

	// TC --> O(n*m) + O(n*m * log(n*m))
	// SC --> O(n*m)
}

int upperBound(vector<int> &arr, int target) {
	int low = 0, high = arr.size() - 1;
	int ans = arr.size();

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (taregt < arr[mid]) {
			ans = mid;
			high = mid - 1;
		}

		else low = mid + 1;
	}

	return ans;
}

// Optimal Approach --> Using Binary Search
// Time and Space Optimised
// The median is the smallest number that is greater than or equal to
// atleast (n*m)/2 elements in the list.
int matrixMedian(vector<vector<int>> &matrix) {
	int row = matrix.size();
	int col = matrix[0].size();

	int low = 1;
	int high = 1e9; // approx 2^32

	// we can also take high as the max element in the matrix
	// but the comparision for max element will take O(row) time.
	// if the matrix contains large amount of rows then it will increase the time complexity

	while (low <= high) {  // this loop will run for 32 times.

		// step 1 --> let mid be the median of the matrix
		int mid = low + (high - low) / 2;

		// step 2 --> count the elements smaller than or equal to mid
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			// count of elments smaller than mid in the row
			cnt += upperBound(matrix[i], mid);
		}


		// if total count is greater than (n*m)/2,then it can be an answer
		// so move to the left to check if any other smaller exists which
		// satisfy the conditio
		// else move right

		if (cnt  >  (n * m / 2)) high = mid - 1;

		else low = mid + 1;
	}

	return low;

	// TC --> O(32 * n * n*(logm));
	// outer while loop runs for 32 times
	// inner for loop runs for n times where one iteration takes logm time
	// So, TC --> O(n*logm)
	// SC --> O(1)

}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, m, k, temp;
	cin >> n >> m ;
	vector<vector<int>> matrix;
	for (int i = 0; i < n; i++) {
		vector<int>row;
		for (int j = 0; j < m; j++) {
			cin >> temp;
			row.push_back(temp);
		}

		matrix.push_back(row);
	}

	int ans = matrixMedian(matrix);
	cout << ans << endl;
}