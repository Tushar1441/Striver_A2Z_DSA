#include <bits/stdc++.h>
using namespace std;


// // Brute force approach --> try out all the possibilities using recursion.
// bool solve(int idx, string s, int left, vector<vector<int>>&dp) {
// 	if (idx == s.size())return left == 0;

// 	if (s[idx] == '(') {
// 		return solve(idx + 1, s, left++, dp);
// 	}

// 	if (s[idx] == ')') {
// 		return solve(idx + 1, s, left--, dp);
// 	}

// 	if (dp[idx][left] != -1)return dp[idx][left];

// 	bool fs = 0, ss = 0, ts = 0;
// 	if (s[idx] == '*') {
// 		fs = solve(idx + 1, s, left, dp);
// 		ss = solve(idx + 1, s, left + 1, dp);
// 		ts = solve(idx + 1, s, left--, dp);
// 	}

// 	return dp[idx][left] = (fs | ss | ts);
// }



// Optimal Approach --> Using Greedy Algorithm.
bool checkValidString(string s) {
	int n = s.size();
	// we are initialising two variables
	// one contains the min possible left parantheses count that happens when
	// we convert all the '*' into ')'.
	// other is the max possible left parantheses count that occurs if
	// we convert all the '*' to '('
	int leftMin = 0, leftMax = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			leftMin++; leftMax++;
		}
		else if (s[i] == ')') {
			leftMin--; leftMax--;
		}
		else {
			leftMin--; leftMax++;
		}

		// if at any point the right parantheses exceeds the max left parantheses
		// then return false.
		if (leftMax < 0)return false;

		// we would never change '*' into ')', if there is no need.
		// or we can say that both the left and right parantheses are balanced.
		if (leftMin < 0)leftMin = 0;
	}

	return leftMin == 0;

	// TC --> O(N);
	// SC --> O(1);

}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<int>>dp(n, vector<int>(n, -1));
	cout << solve(0, s, 0, dp) << endl;
	// cout <<  checkValidString(s) << endl;

}