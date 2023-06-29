#include <bits/stdc++.h>
using namespace std;


int shortestCommonSupersequence(string text1, string text2) {
	int n = text1.size();
	int m = text2.size();

	vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
	// to accomodate the base case we have shifted the indexes by one place.

	//base case --> if idx1 == 0 or idx2 == 0, return 0.
	for (int j = 0; j <= m; j++)dp[0][j] = 0;
	for (int j = 0; j <= n; j++)dp[j][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (text1[i - 1] == text2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}

			else {
				dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
			}

		}
	}


	int i = n;
	int j = m;

	string ans = "";

	while (i > 0 && j > 0) {
		if (text1[i - 1] == text2[j - 1]) {
			ans += text1[i - 1];
			i--;
			j--;
		}

		//if top element is greater then move to top and add the left element to
		else if (dp[i - 1][j] > dp[i][j - 1]) {
			ans += text1[i - 1];
			i--;
		}
		// else move to left and add the top element to the answer
		else {
			ans += text2[j - 1];
			j--;
		}
	}

	//Adding Remaing Characters - Only one of the below two while loops will run

	while (i > 0) {
		ans += text1[i - 1];
		i--;
	}
	while (j > 0) {
		ans += text2[j - 1];
		j--;
	}

	reverse(ans.begin(), ans.end());
	return ans;

	// TC --> O(n*m)
	// SC --> O(n*m)
}

int lps(string word1, string word2) {
	int n = word1.length();
	int m = word2.length();

	return optimizedTabulationWay(word1, word2);
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
