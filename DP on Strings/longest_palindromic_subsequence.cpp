#include <bits/stdc++.h>
using namespace std;



// Reverse the string and store it in a variable.
// then find the longest common subsequence in both the strings.

int optimizedTabulationWay(string text1, string text2) {
	int n = text1.size();
	int m = text2.size();

	vector<int>prev(m + 1, 0), curr(m + 1, 0);
	prev[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (text1[i - 1] == text2[j - 1]) {
				curr[j] = 1 + prev[j - 1];
			}

			else {
				curr[j] = max(prev[j] , curr[j - 1]);
			}

		}
		prev = curr;
	}

	return prev[m];

	// TC --> O(n*m)
	// SC --> O(m) --> storing only 1D array.
}

int lps(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	return optimizedTabulationWay(s, t);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	string a, b;
	cin >> a;

	cout << lps(a) << endl;
}



// Other Tried approach

// // simple recursive solution
// // divide the string into two halves.
// // compare the elements from the start of the first half and ending of the second half.
// // till both the pointer crosses each other.
// int solve(int idx1, int idx2 , string &s) {
// 	if (idx2 < idx1)return 0;

// 	if (s[idx1] == s[idx2]) {
// 		if (idx1 == idx2) return 1 + solve(idx1 + 1, idx2 - 1, s);
// 		return 2 + solve(idx1 + 1, idx2 - 1, s);
// 	}
// 	return max(solve(idx1 + 1, idx2, s) , solve(idx1, idx2 - 1, s));

// 	// TC --> O(2^n)
// 	// SC --> O(n) --> recursion stack space.
// }



// int solveMemoWay(int idx1, int idx2 , string &s, vector<vector<int>>&dp) {
// 	// if indexes crosses, then return.
// 	if (idx2 < idx1)return 0;

// 	// if elements are same, move both the pointers
// 	if (s[idx1] == s[idx2]) {
// 		// if indexes are same, add only one element.
// 		if (idx1 == idx2) return dp[idx1][idx2] =  1 + solveMemoWay(idx1 + 1, idx2 - 1, s, dp);
// 		// else add two char length to the answer length.
// 		return dp[idx1][idx2] = 2 + solveMemoWay(idx1 + 1, idx2 - 1, s, dp);
// 	}

// 	// else move both the pointers one by one.
// 	return dp[idx1][idx2] = max(solveMemoWay(idx1 + 1, idx2, s, dp) , solveMemoWay(idx1, idx2 - 1, s, dp));
// }