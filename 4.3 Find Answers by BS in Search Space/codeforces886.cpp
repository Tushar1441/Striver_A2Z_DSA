#include <bits/stdc++.h>
using namespace std;


void solve() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a + b > 9 || b + c > 9 || a + c > 9)cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}