#include <bits/stdc++.h>
using namespace std;



// Brute Force Approach - traversing the complete 2d array in a single loop
bool search_in_matrix1(vector<vector<int>> &arr, int k) {
	int row = arr.size();
	int col = arr[0].size();


	for (int i = 0; i < row * col; i++) {
		if (arr[i / row][i % col] == k) {
			//the index of the element will be ( i / row, i % col );
			return true;
		}
	}

	return false;
	// TC --> O(m*n) (total number of elements in the 2d array)
	// SC --> O(1) (no extra space required)
}



// Better Solution --> Binary Search on every row
bool search_in_matrix2(vector<vector<int>> &arr, int k) {
	int row = arr.size();
	int col = arr[0].size();


	for (int i = 0; i < row; i++) {
		int low = 0;
		int high = col - 1;

		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[i][mid] == k )return true;
			else if (arr[i][mid] < k)low = mid + 1;
			else high = mid - 1;
		}

	}

	return false;
	// TC --> O(m*logn) (binary search on n elements for m times)
	// SC --> O(1) (no extra space required)
}




// The array is sorted row-wise so we can reduce the time complexity for the first approach
// from O(m*n) to O(m+n) by simply putting a check for the availability of the element in the row.
bool search_in_matrix3(vector<vector<int>> &arr, int k) {
	int row = arr.size();
	int col = arr[0].size();


	for (int i = 0; i < row; i++) {

		// putting a boundary check if the target is less than the last element of the row and greater
		// than the first element of the row.
		if (arr[i][col - 1] >= k && arr[i][0] <= k) {
			int j = 0;
			// check the row for the element
			while (j < col) {
				if (arr[i][j] == k)return true;
				j++;
			}

			return false;
		}
	}

	return false;
	// TC --> O(m + n) (m for the outer loop and n for the inner loop(once))
	// SC --> O(1) (no extra space required)
}



// Optimal Solution --> Binary Search on complete Matrix
bool search_in_matrix4(vector<vector<int>> &arr, int k) {
	int row = arr.size();
	int col = arr[0].size();

	int lo = 0;
	int high = row * col - 1;

	while (lo <= high) {
		int mid = lo + (high - lo) / 2;

		if (arr[mid / col][mid % col] == k) {
			return true;
		}

		else if (arr[mid / col][mid % col] < k) {
			lo = mid + 1;
		}

		else {
			high = mid - 1;
		}

	}

	return false;
	// TC --> O(log(n*m)) (binary search on n*m elements)
	// SC --> O(1) (no extra space required)
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int m, n, k, temp;
	cin >> m >> n >> k ;

	vector<vector<int>> arr(m);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			arr[i].push_back(temp);
		}
	}

	bool ans = search_in_matrix(arr, k);
	cout << ans << endl;

}