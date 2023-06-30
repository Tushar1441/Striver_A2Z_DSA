#include <bits/stdc++.h>
using namespace std;


int findNumberOfLIS(vector<int>& arr) {
	int n = arr.size();

	// dp array gives the value of LIS ending at that index.
	vector<int> dp(n, 1);
	// ct array gives us the count of LIS occuring at that index.
	vector<int> ct(n, 1);

	int maxi = 1;

	for (int i = 0; i <= n - 1; i++) {
		for (int prev = 0; prev <= i - 1; prev ++) {

			if (arr[prev] < arr[i] && dp[prev] + 1 > dp[i]) {
				dp[i] = dp[prev] + 1;
				//inherit
				ct[i] = ct[prev];
			}
			else if (arr[prev] < arr[i] && dp[prev] + 1 == dp[i]) {
				//increase the count
				ct[i] = ct[i] + ct[prev];
			}
		}
		maxi = max(maxi, dp[i]);
	}

	int nos = 0;
	// check how many times the max LIS is appearing in the dp array.
	for (int i = 0; i <= n - 1; i++) {
		if (dp[i] == maxi) nos += ct[i];
	}

	return nos;
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
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	cout << findNumberOfLIS(arr) << endl;
}