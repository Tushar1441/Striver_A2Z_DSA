#include <bits/stdc++.h>
using namespace std;


bool solve(int idx, vector<int>arr, vector<int>&dp) {
	if (arr[idx] == 0)return 0;
	if (idx >= arr.size())return false;
	if (idx == arr.size() - 1)return true;

	if (dp[idx] != -1)return dp[idx];

	bool ans = 0;
	for (int i = 1; i <= arr[i]; i++) {
		bool curr =  solve(idx + i, arr, dp);
		ans = ans | curr;
	}

	return dp[idx] = ans;

	// TC --> O(n*k) where k is the maximum value of the arr[i].
	// for simple recurence solution, TC will be O(n^k)
	// SC --> O(n) + O(n) recursion stack space + dp array
}



// tabulation approach
bool solve1(vector<int>arr) {
	int n = arr.size();
	vector<int>dp(n, -1);
	dp[n - 1] = 0;


	for (int i = n - 2; i >= 0; i--) {
		bool ans = 0;
		if (arr[i] != 0) {
			for (int j = 1; j <= arr[i]; j++) {
				bool curr =  dp[i - j];
				ans = ans | curr;
			}
		}

		dp[i] = ans;
	}

	return dp[0];

	// TC --> O(N*k)  where k is the maximum value of the arr[i].
	// SC --> O(N) --> dp array
}



// Optimal solution --> Greedy Approach
// shift the destination from left
bool solve2(vector<int>&nums) {
	int n = nums.size();
	int goal = n - 1;

	for (int i = n - 1; i >= 0; i--) {
		// From any position, if we can reach the goal or beyond
		// by doing max number of jumps on that position,
		// shift the goal to that position and move backwards.
		if (i + nums[i] >= goal)goal = i;
	}

	//if the goal is shifted to 0th index, then return true, else return false.
	return (goal == 0);
}




bool canJump(vector<int>& nums) {
	int n = nums.size();
	vector<int>dp(n, -1);
	return solve1(nums);
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

	cout << canJump(arr) << endl;


}