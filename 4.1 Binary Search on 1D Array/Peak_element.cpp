#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach --> Linearly traverse in the array
int peakElement1(vector<int> &arr) {
	int n = arr.size();

	if (arr[0] >= arr[1]) // if arr[0] is peak element
		return arr[0];

	for (int i = 1; i < n - 1; i++) {
		if ((arr[i] > arr[i - 1] ) && (arr[i] > arr[i + 1] )) {
			return i;
		}
	}

	return arr[n - 1]; // if no peak is found then last element will be peak.

// TC --> O(n)
// SC --> O(1)
}



// Optimal Solution --> Using Binary Search
int peakElement(vector<int> &arr) {
	int n = arr.size();
	int low = 0;
	int high = n - 1;

	while (low <= high) {

		int mid = low + (high - low) / 2;
		cout << mid << " ";
		if (mid == 0) {
			if (arr[mid] > arr[mid + 1])return mid;
			else low = mid + 1;
		}

		if (mid == n - 1) {
			if (arr[mid] > arr[mid - 1])return mid;
			else high = mid - 1;
		}

		if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
			return mid;
		}

		else if (arr[mid] < arr[mid - 1]) {
			high = mid - 1;
		}

		else {
			low = mid + 1;
		}
	}

	return -1;
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

	int ans = peakElement(arr);

	cout << ans << endl;

}