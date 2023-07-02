#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach --> Using Two For loops
int sumSubarrayMins(vector<int>&nums) {
	int n = nums.size();
	int res = 0;

	for (int i = 0; i < n; i++) {
		int mini = INT_MAX;
		for (int j = i; j < n; j++) {
			if (nums[j] < mini) {
				mini = nums[j];
			}
			res += mini;
		}
	}

	return res;

	// TC --> O(N^2)
	// SC --> O(1)
}


int sumSubarrayMins1(vector<int>&nums) {
	int n = nums.size();
	int res = 0;

	int mini = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (nums[i] < mini) {
			mini = nums[i];
		}
		res = res + i * mini + nums[i];
	}

	return res;
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
	vector<int>nums1;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		nums1.push_back(temp);
	}
	cout << sumSubarrayMins1(nums1) << endl;
}
