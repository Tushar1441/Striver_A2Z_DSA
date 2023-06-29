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

int lps(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	return s.length() - optimizedTabulationWay(s, t);
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
