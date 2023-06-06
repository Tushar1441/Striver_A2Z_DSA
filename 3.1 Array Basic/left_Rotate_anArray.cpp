#include <bits/stdc++.h>
using namespace std;


// TC --> O(n)
// SC --> O(d) = (due to temp array)
void BruteForceApproach(vector<int> &arr, int n, int d) {

	d = d % n;

	// Step 1: Copy the first d elements into the temp array.
	int temp[d];
	for (int i = 0; i < d; i++) {
		temp[i] = arr[i];
	}

	// Step 2: Shift n-d elements from last by d position to the left
	for (int i = 0; i < n - d; i++) {
		arr[i] = arr[i + d];
	}

	// Step 3: Copy the elements into the main array from the temp array.
	for (int i = n - d; i < n; i++) {
		arr[i] = temp[i - n + d];
	}

}



// Time Complexity – O(N) where N is the number of elements in an array
// Space Complexity – O(1) since no extra space is required
void leftRotateByD(vector<int> &arr, int n, int d) {
	d = d % n;

	// reverse the left array-->
	for (int i = 0; i < d / 2; i++) {
		swap(arr[i], arr[d - i - 1]);
	}

	// reverse the remaining array-->
	for (int i = d; i < (n + d) / 2; i++) {
		swap(arr[ i], arr[n + (d - i) - 1]);
	}

	// reverse the complete array-->
	for (int  i = 0; i < n / 2; i++) {
		swap(arr[i], arr[n - i - 1]);
	}
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, k, temp;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;
	}
	leftRotateByD(arr, n, k
	             );
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}