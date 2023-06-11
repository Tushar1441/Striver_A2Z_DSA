#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution
int KthMissingPositiveIntegar1(vector<int> &arr , int k) {
	int n = arr.size(), count = 0;
	int last = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] != last + 1) {
			count += (arr[i] - last - 1);
			last = arr[i];
		}

		else last++;

		if (count >= k) {
			return (arr[i] - (count - k + 1));
		}
	}

	return arr[n - 1] + (k - count);
	// TC --> O(n)
}


// Optimal Solution -- using Binary Search
int KthMissingPositiveIntegar(vector<int> &arr, int k) {
	int n = arr.size();
	int low = 0, high = n - 1, mid;

	while (low <= high) {
		mid = (low + high) >> 1;

		if (low == high) {
			return ( arr[mid] - (arr[mid] - mid - 1) + k  );
		}

		if (arr[mid] - (mid + 1) < k) {
			low = mid + 1;
		}

		else high = mid - 1;
	}

	return arr[n - 1] + (k - (arr[n - 1] - n - 1));
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

	cout << KthMissingPositiveIntegar(arr, k) << endl;


}

