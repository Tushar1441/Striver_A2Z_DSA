#include <bits/stdc++.h>
using namespace std;

// brute force approach
int maxSum(vector<int>&arr, int k) {
	int ans = 0;

	int n = arr.size();
	for (int i = 0; i < n; i++) {
		if (i + k <= n) {
			int sum = 0;
			for (int j = i; j < i + k; j++) {
				sum += arr[j];
			}

			ans = max(ans, sum);
		}
	}

	return ans;

	// TC --> O(n^2)
	// SC --> O(1)
}


// Optimal Approach
// we can use previous calculations using sliding window algorithm
int maxSum1(vector<int>arr, int k) {
	int n = arr.size();
	int ans = 0;

	int right = 0, left = 0;

	int sum = 0;
	while (right < n) {

		sum += arr[right];

		// subtract arr[left] and move the left pointer by one position.
		if (right > k - 1) {
			sum -= arr[left];
			left++;
		}

		if (right - left == k - 1)ans = max(sum, ans);
		right++;
	}

	return ans;

	// TC --> O(n)
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

	cout << maxSum1(arr, k) << endl;
}