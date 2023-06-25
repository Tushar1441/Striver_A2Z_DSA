#include <bits/stdc++.h>
using namespace std;

// brute force approach --> try out all the possible combinations.
int solve(int idx, vector<int>arr, int target) {

	if (idx == -1) {
		if (target == 0)return 1;
		return 0;
	}
	//pick
	int add = solve(idx - 1, arr, target - arr[idx]);

	// not pick
	int remove = solve(idx - 1, arr, target + arr[idx]);
	return (add + remove);

	//TC --> O(2^n) here t is the max target.
	// SC --> O(n)
}


/*
If we try to think deeply, this problems becomes exactly similar to the partition with
given difference problem.
we are trying to add some elements value into the sum and then reduce some elements value.

suppose an array --> [a,b,c,d,e] and target = k;
if a possible solution for this array is --> a+b-c-d+e .
then it can also be written as (a+b+e) - (c+d) ==> s1 - s2 == k

s2 = totalSum - s1
s1 = k -s2
s2 = (totalSum - k)/2


Since all the array elements are positive, s1 and s2 cannot be negative.
totalSum - k => it cannot be odd because s2 can't be a fraction value.
*/


int solveMemoWay(int ind, int target, vector<int>& arr, vector<vector<int>> &dp) {
	if (ind == 0) {
		if (target == 0 && arr[0] == 0)
			return 2;
		if (target == 0 || target == arr[0])
			return 1;
		return 0;
	}

	if (dp[ind][target] != -1)
		return dp[ind][target];

	int notTaken = countPartitionsUtil(ind - 1, target, arr, dp);

	int taken = 0;
	if (arr[ind] <= target)
		taken = countPartitionsUtil(ind - 1, target - arr[ind], arr, dp);

	return dp[ind][target] = (notTaken + taken);
}


// tabulation top down approach
int tabulationWay(int k, vector<int>& num) {
	int n = num.size();

	vector<vector<int>> dp(n, vector<int>(k + 1, 0));

	if (num[0] == 0) dp[0][0] = 2; // 2 cases -pick and not pick
	else dp[0][0] = 1;  // 1 case - not pick

	if (num[0] != 0 && num[0] <= k) dp[0][num[0]] = 1; // 1 case -pick

	for (int ind = 1; ind < n; ind++) {
		for (int target = 0; target <= k; target++) {

			int notTaken = dp[ind - 1][target];

			int taken = 0;
			if (num[ind] <= target)
				taken = dp[ind - 1][target - num[ind]];

			dp[ind][target] = (notTaken + taken) ;
		}
	}
	return dp[n - 1][k];
}


int findWays(vector<int> &num, int tar) {
	int n = num.size();

	vector<int> prev(tar + 1, 0);

	if (num[0] == 0) prev[0] = 2; // 2 cases -pick and not pick
	else prev[0] = 1;  // 1 case - not pick

	if (num[0] != 0 && num[0] <= tar) prev[num[0]] = 1; // 1 case -pick

	for (int ind = 1; ind < n; ind++) {
		vector<int> cur(tar + 1, 0);
		for (int target = 0; target <= tar; target++) {
			int notTaken = prev[target];

			int taken = 0;
			if (num[ind] <= target)
				taken = prev[target - num[ind]];

			cur[target] = (notTaken + taken);
		}
		prev = cur;
	}
	return prev[tar];
}


int targetSum(int n, int target, vector<int>& arr) {
	int totSum = 0;
	for (int i = 0; i < arr.size(); i++) {
		totSum += arr[i];
	}

	//Checking for edge cases
	if (totSum - target < 0) return 0;
	if ((totSum - target) % 2 == 1) return 0;

	int s2 = (totSum - target) / 2;
	// vector<map<int, int>> dp(n, vector<int>(s2 + 1, -1));
	// return  solveMemoWay(n - 1, s2, arr, dp);

	return findWays(arr, s2);
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

	cout << targetSum(n, k, arr) << endl;

}