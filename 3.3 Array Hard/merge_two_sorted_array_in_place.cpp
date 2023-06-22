#include <bits/stdc++.h>
using namespace std;

// this is not a exact solution to the problem as we are using some
// extra space but the question does not have any such constraints.
// so just do simple merging in a new array and then transfer all
// the elements to arr1.
void mergeArrays1(vector<int>&arr1, vector<int>&arr2, int m, int n) {

	int *arr = new int[m + n];

	int i = 0, j = 0, k = -1;

	while (i < m && j < n) {
		if (arr1[i] <= arr2[j]) {
			arr[k + 1] = arr1[i];
			i++;
		}
		else {
			arr[k + 1] = arr2[j];
			j++;
		}
		k++;
	}

	while ( k < (m + n) ) {
		if (i != m) {
			arr[k + 1] = arr1[i]; i++; k++;
		}
		else {
			arr[k + 1] = arr2[j]; j++; k++;
		}
	}

	for (int i = 0; i < m + n; i++) {
		arr1[i] = arr[i];
	}

	delete []arr;

	return;

	// TC --> O(m+n)
	// SC --> O(m+n)
}


// fill the larger elements first from behind in the arr1 itself
void mergeArrays(vector<int>&arr1, vector<int>&arr2, int m, int n) {

	// all pointers pointing to last indexes
	int i = m - n - 1, j = n - 1, k = m - 1;

	while (i >= 0  && j >= 0) {
		if (arr1[i] >= arr2[j]) {
			arr1[k] = arr1[i];
			i--;
		}
		else {
			arr1[k] = arr2[j];
			j--;
		}
		k--;
	}

	while ( k >= 0 ) {
		if (i != -1) {
			arr1[k] = arr1[i]; i--; k--;
		}
		else {
			arr1[k] = arr2[j]; j--; k--;
		}
	}


	return;

	// TC --> O(N+M)
	// SC --> O(1)
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int m, n, temp;
	cin >> m >> n;

	vector<int> arr1;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		arr1.push_back(temp);
	}

	vector<int> arr2;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr2.push_back(temp);
	}

	mergeArrays(arr1, arr2, m , n);

	for (auto it : arr1)cout << it << " ";
	cout << endl;
}