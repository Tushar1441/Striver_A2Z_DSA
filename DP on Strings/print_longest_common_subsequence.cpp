#include <bits/stdc++.h>
using namespace std;

int printLCS(string text1, string text2) {
	int n = text1.size();
	int m = text2.size();

	vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));

	for (int j = 0; j <= m; j++)dp[0][j] = 0;
	for (int j = 0; j <= n; j++)dp[j][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (text1[i - 1] == text2[idx2 - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}

			else {
				dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
			}

		}
	}

	/*

	e.g  for s1 = 'abcde' , s2 = 'bdgek'

	the dp array for these strings will be -->
	-	-	-  b d g e k
	-	-	0 1 2 3 4 5
	-	0	0 0 0 0 0 0
	a	1	0 0 0 0 0 0
	b	2   0 1 1 1 1 1
	c	3   0 1 1 1 1 1
	d	4	0 1 2 2 2 2
	e	5   0 1 2 2 3 3

	Just observe this dp array carefully ->
	 dp[5][5] signifies s1[5] and s2[5] have 3 size max LCS.
	 dp[4][2] signifies s1[4] and s2[2] have 2 size max LCS.

	*/

	int len = dp[n][m];
	int i = n;
	int j = m;

	int index = len - 1;
	// initialise a empty dummy string and fill some dummy len characters.
	string str = "";
	for (int i = 0; i < len; i++) {
		str += '&';
	}


	while (i > 0 && j > 0) {
		// if same element found then update the answer string
		if (text1[i - 1] == text2[j - 1]) {
			str[index] = s1[i - 1];
			index--;
			i--; j--;
		}

		else if (text1[i - 1] > text2[j - 1])i--;
		else j--;
	}

	cout << str;

	// TC --> O(n*m) + O(len)
	// SC --> O(n*m) + O(len)
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	string a, b;
	cin >> a >> b;

	cout << printLCS(a, b) << endl;
}