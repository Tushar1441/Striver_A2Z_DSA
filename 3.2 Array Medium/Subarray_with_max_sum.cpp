#include <bits/stdc++.h>
using namespace std;



// Brute Force Approach --> calculate sum of all subarrays
long long maxSubarraySum1(vector<int> &arr) {
	int n = arr.size();
	long long maxSum = 0;

	for (int i = 0; i < n; i++)
	{
		long long sum = arr[i];
		for (int j = i + 1; j < n; j++)
		{
			sum += arr[j];
			maxSum = max(maxSum , sum);
		}
	}

	return maxSum;

	// TC--> O(n^2) -- two nested for loops;
	// SC --> O(1)

}

// Optimal Solution -->
// The intuition of the algorithm is not to consider the subarray as a part of the answer
// if its sum is less than 0. A subarray with a sum less than 0 will always reduce our answer
// and so this type of subarray cannot be a part of the subarray with maximum sum.

long long maxSubarraySum(vector<int> &arr) {
	int n = arr.size();
	long long sum = 0;
	long long maxSum = INT_MIN;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum < 0) {
			sum = 0;
		}

		maxSum = max(maxSum, sum);
	}

	return maxSum;

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
	int n, temp;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	long long ans = maxSubarraySum(arr);

	cout << ans << endl;

}