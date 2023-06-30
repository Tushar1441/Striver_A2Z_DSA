#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>&nums) {
	int n = nums.size();

	// initialise a dp array with value of 1.
	vector<int>dp(n, 1);

	// update the dp array for every index.
	for (int i = 0; i < n; i++) {
		for (int prev = 0; prev < i; prev++) {
			if (nums[i] > nums[prev]) {
				dp[i] = max(dp[i], 1 + dp[prev]);
			}
		}
	}

	// find the max length find in the dp array.
	int ans = -1;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}

	return ans;
}

int printLIS(vector<int>&nums) {
	int n = nums.size();

	// initialise a dp array with value of 1.
	vector<int>dp(n, 1);
	vector<int>hash(n, 1);


	// update the dp array for every index.
	for (int i = 0; i < n; i++) {
		hash[i] = i;
		for (int prev = 0; prev < i; prev++) {
			if (nums[i] > nums[prev] && dp[i] < 1 + dp[prev]) {
				dp[i] = 1 + dp[prev];
				hash[i] = prev;
			}
		}
	}

	// find the max length find in the dp array.
	int ans = -1;
	int lastIndex = -1;

	for (int i = 0; i < n; i++) {
		if (dp[i] > ans) {
			ans = dp[i];
			lastIndex = i;
		}
	}


	// initialise a ans array
	vector<int>temp;
	temp.push_back(nums[lastIndex]);

	while (hash[lastIndex] != lastIndex) {
		lastIndex = hash[lastIndex];
		temp.push_back(nums[lastIndex]);
	}

	// reverse the array
	reverse(temp.begin(), temp.end());

	for (int i = 0; i < temp.size(); i++) {
		cout << temp[i] << " ";
	}
	cout << endl;

	return ans;
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

	cout << printLIS(arr) << endl;
}