#include <bits/stdc++.h>
using namespace std;


bool checkPalindrome(int i, string s, int n) {
	if (i >= n / 2) {
		return true;
	}

	if (s[i] != s[n - i - 1]) {
		return false;
	}

	return checkPalindrome(i + 1, s, n);
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
	int n = s.length();
	cout << checkPalindrome(0, s, n );

}