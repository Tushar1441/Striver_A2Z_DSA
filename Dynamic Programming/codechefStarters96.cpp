#include <bits/stdc++.h>
using namespace std;


void solve() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	int Alice = max(a + b, max(a + c, b + c));
	int Bob = max(d + e, max(d + f, f + e));

	if (Alice > Bob)cout << "ALICE" << endl;
	else if (Bob > Alice)cout << "Bob" << endl;
	else cout << "TIE" << endl;

}


void solve1() {
	int n;
	cin >> n;
	string a, b, c;
	cin >> a >> b >> c;

	int x = (b[0] - a[0]);
	string ans = "";

	for (int i = 0; i < c.length(); i++) {
		int y = (c[i] - 'a' + x);

		if (y > 25) {
			ans += (char)('a' + (y - 28));
		}
		else if (y < 0) {
			ans += (char)('z' + y);
		}
		else {
			cout << y << endl;
			ans += ('a' + y);
		}
	}

	cout << ans << endl;
}

void solve2() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int ans = 0;
	int right = 0;
	while (right < n) {
		if (s[right] == ':') {
			right++;
			int flag = 0;
			while (right < n  && s[right] != ':' ) {
				if (s[right] == ')')flag = 1;
				if (s[right] == '(') {
					flag = 0; break;
				}
				// cout << right << " ";
				right++;
			}

			if (flag == 1 && s[right] == ':')ans++;
		}

		if (s[right] != ':')right++;

	}

	cout << ans << endl;
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
		solve1();
	}
}