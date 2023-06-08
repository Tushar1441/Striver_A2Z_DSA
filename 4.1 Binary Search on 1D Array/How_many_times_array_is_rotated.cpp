#include <bits/stdc++.h>
using namespace std;

// We just have to find the minimum element index.


// Brute Force Solution --> using linear search
// TC -- O(n)
// SC -- O(1)


// Optimal Solution --> Using Binary Search
int minimumInRotatedSortedArray(vector<int> &arr) {
	int low = 0, high = arr.size() - 1;
	int ans = INT_MAX; // minimum element in rotated sorted array
	int index = -1; // index of minimum element


	while (low <= high) {

		int mid = low + (high - low) / 2;

		//if the search space is already sorted then arr[low] will be the minimum
		if (arr[low] <= arr[high]) {
			if (arr[low] < ans) {
				ans = arr[low];
				index = low;
			}
			break;
		}

		if (arr[mid] >= arr[low]) { // if the left half is sorted
			if (arr[low] < ans) {
				ans = arr[low];
				index = low;
			}
			low = mid + 1;
		}

		else {    // if the right half is sorted
			if (arr[low] < ans) {
				ans = arr[low];
				index = mid;
			}
			high = mid - 1;
		}
	}

	return index;

	// TC --> O(logn)
	// SC --> O(1)

}





int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, temp;
	cin >> n ;
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	int ans = minimumInRotatedSortedArray(arr);

	cout << ans << endl;

}