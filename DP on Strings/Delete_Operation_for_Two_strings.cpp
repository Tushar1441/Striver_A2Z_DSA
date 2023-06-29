#include <bits/stdc++.h>
using namespace std;


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

int lps(string word1, string word2) {
	int n = word1.length();
	int m = word2.length();

	int common = optimizedTabulationWay(word1, word2);

	return (n + m - 2 * common);
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
