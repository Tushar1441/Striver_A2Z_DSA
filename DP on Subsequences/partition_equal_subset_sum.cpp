#include <bits/stdc++.h>
using namespace std;


//recursive solution
bool f(int idx, vector<int>&arr, int target) {

	if (target == 0 )return 1;
	if (idx == 0)return (arr[0] == target);

	//pick the current element only if it is less than the target
	bool pick = false;
	if (target >= arr[idx]) {
		pick = f(idx - 1, arr, target - arr[idx]);
	}

	// not pick the current element
	bool notpick = f(idx - 1, arr, target);

	return (pick || notpick);

	// TC --> O(2^n)
	// SC --> O(N)
}


// using memoization
bool f1(int idx, vector<int>&arr, int target, vector<vector<int>>&dp) {
	if (target == 0)return 1;
	if (idx == 0)return (arr[0] == target);

	if (dp[idx][target] != -1)return dp[idx][target];

	//pick the current element only if it is less than the target
	bool pick = false;
	if (target >= arr[idx]) {
		pick = f1(idx - 1, arr, target - arr[idx], dp);
	}

	// not pick the current element
	bool notpick = f1(idx - 1, arr, target, dp);

	return dp[idx][target] = (pick || notpick);

	// TC --> O(n*k)
	// SC --> O(n) + O(n*k)
}


bool f2(int n, vector<int>&arr, int target) {

	//intialise dp vector with all falsy values.
	vector<vector<bool>>dp(n, vector<bool>(target + 1, 0));

	//step1 ) write base case

	// here first base case is if target == 0 ? return true.
	// so for every index, if target is 0, store true/1.
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
	}

	// second base case if index == 0 ? return (a[0] == target)
	if (arr[0] <= target)dp[0][arr[0]] = 1;


	// explore various states.
	for (int i = 1; i < n; i++ ) {
		for (int k = 1; k <= target; k++) {
			bool pick = 0;
			if (k >= arr[i]) {
				pick = dp[i - 1][k - arr[i]];
			}

			bool notpick = dp[i - 1][k];


			dp[i][k] = pick || notpick;
		}
	}

	return dp[n - 1][target];

	// TC --> O(n*k)
	// SC -- O(n*k)

}

// space optimisation
bool f3(int n, vector<int>&arr, int target) {

	//initialse a 1D vector
	vector<int>prev(target + 1, 0), curr(target + 1, 0);

	for (int i = 0; i < n; i++) {
		prev[0] = 1;
	}

	if (arr[0] <= target) prev[arr[0]] = 1;


	// explore various states.
	for (int i = 1; i < n; i++ ) {
		for (int k = 1; k <= target; k++) {
			bool pick = 0;
			if (k >= arr[i]) {
				pick = prev[k - arr[i]];
			}

			bool notpick = prev[k];


			curr[k] = pick || notpick;
		}

		prev = curr;
	}

	return prev[target];

	// TC --> O(n*k)
	// SC -- O(k)
}


bool canPartition(vector<int> &arr, int n) {
	int totalSum = 0;
	for (int i = 0; i < n; i++) {
		totalSum += arr[i];
	}

	// if the totalsum of all the array elements is odd
	// then it cannot be divided into two equal parts.
	if (totalSum & 1)return false;

	vector<vector<int>>dp(n, vector<int>(totalSum + 1, -1));
	//if sum is even, then just find if a subset with sum == totalsum/2
	// exists in the array or not.
	// if it exists then the remaining subset sum will automatically become totalsum/2.
	return f1(n - 1, arr, totalSum / 2, dp);
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

	cout << canPartition(arr, n) << endl;

}