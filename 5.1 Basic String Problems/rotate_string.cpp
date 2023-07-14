#include <bits/stdc++.h>
using namespace std;


bool rotateString(string s, string t) {
	int n = s.length();
	int m = t.length();

	if (n != m)return false;

	int i = 0;
	for (i; i < n; i++) {
		if (t[i] == s[0]) {
			break;
		}
	}

	for (int j = 0; j < n; j++) {
		if (s[j] != t[(i + j) % n])return false;
	}

	return true;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	string s, t;
	cin >> s >> t;

	cout << rotateString(s, t) << endl;
}

