#include <bits/stdc++.h>
using namespace std;

string largestOdd(string &s) {
	int n = s.size(), breakpoint = -1;
	// string ans = "";
	for (int i = n - 1; i >= 0; i--) {
		if ((int)s[i] & 1) {
			breakpoint = i;
			// ans += s.substr(0, i + 1);
			break;
		}
	}

	s.erase(breakpoint + 1, n - 1 - breakpoint );
	return s;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	string s ;
	cin >> s;

	string ans = largestOdd(s);
	cout << ans << endl;

}

