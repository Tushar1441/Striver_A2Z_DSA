#include <bits/stdc++.h>
using namespace std;


int solve(string s, int i, int sign) {
	// base case -> empty string
	if (s == '' || i == s.size()) {
		return 0;
	}

	// Skip leading whitespace
	if (s[i] == ' ') {
		return  solve(s, i + 1, sign);
	}

	// Check for optional sign
	if (s[i] == '-') {
		return -solve(s, i + 1, -sign);
	}
	if (s[i] == '+') {
		return solve(s, i + 1, sign);
	}

	// Process the current digit
	if (s[i] >= '0' && s[i] <= '9') {
		return ((s[i] - '0') * sign) + solve(s, i + 1, sign);
	}

	// Invalid character encountered
	return 0;
}



int myAtoiRecursive(string s) {
	return solve(s, 0, 1);
}

int myAtoi(string s) {
	long long res = 0;
	int i = 0;
	int sign = 1;

	// skip leading whitespace
	while (s[i] == ' ')i++;

	// check the sign
	if (s[i] == '+' || s[i] == '-') {
		sign = (s[i++] == '-') ? -1 : 1;
	}

	// process the digits
	while (s[i] >= '0' && s[i] <= '9') {
		res = res * 10 + (s[i++] - '0');

		if (res > INT_MAX || res < INT_MIN) {
			return (res > 0) ? INT_MAX : INT_MIN;
		}
	}

	return res * sign;
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

	cout << myAtoi(s) << endl;

}

