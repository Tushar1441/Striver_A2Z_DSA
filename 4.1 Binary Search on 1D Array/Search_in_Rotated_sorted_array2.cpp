#include <bits/stdc++.h>
using namespace std;


// This question is slight variation of the previous one.
// The array can also contain duplicate elements.

// Brute Force Solution --> using linear search
// TC -- O(n)
// SC -- O(1)



// Optimal Solution --> Using Binary Search
bool searchInRotatedSortedArray2(vector<int> &arr, int target) {
	int low = 0;
	int high = arr.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == target) return true;

		// Only this case will provide differences from the previous problem
		// when arr[low] == arr[mid] == arr[high] then just do low++ and high--
		if (arr[mid] == arr[low] && arr[mid] == arr[high]) {
			low++;
			high--;
			continue;
		}

		if (arr[mid] <= arr[high]) { //if right half is sorted
			if (target > arr[mid] && target <= arr[high])low = mid + 1; //if answer lies in right half
			else high = mid - 1; // else move to left
		}

		else {  // if left half is sorted
			if (target >= arr[low] && target < arr[mid]) { //if answer lies in left half
				high = mid - 1;
			}
			else low = mid + 1; // else move to right
		}
	}

	return false;

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
	int n, k, temp;
	cin >> n >> k;
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	bool ans = searchInRotatedSortedArray2(arr, k);

	cout << ans << endl;

}