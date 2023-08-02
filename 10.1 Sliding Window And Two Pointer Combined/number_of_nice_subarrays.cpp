#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach -> generate all the subarrays
int numberOfSubarrays(int k, vector<int>&nums) {
	int n = nums.size();
	int res = 0;

	for (int i = 0; i < n; i++) {
		int curr = 0;
		for (int j = i; j < n; j++) {
			if (nums[j] & 1) {
				curr++;
			}
			if (curr == k)res++;
		}
	}

	return res;

	// TC --> O(n^2)
}


// Optimal Solution -> Using Sliding Window Technique
int solve(int k, vector<int>&nums) {
	int n = nums.size();
	int res = 0, left = 0, right = 0, curr = 0;

	while (right < n) {
		// increase the curr count
		if (nums[right] & 1)curr++;

		while (curr > k) {
			if (nums[left] & 1)curr--;
			left++;
		}

		res += (right - left + 1);
		right++;
	}

	return res;
}

int numberOfSubarrays1(int k, vector<int>&nums) {
	// we can find the windows with max k odd elements using sliding window
	// To find subarrays with exactly k odd elements -> we can do
	// windows with atmost k elements - windows with atmost k-1 elements
	return solve(k, nums) - solve(k - 1, nums);
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

	cout << numberOfSubarrays1(k, arr) << endl;
}