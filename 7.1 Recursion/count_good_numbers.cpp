#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007;

// Solution 1 --> using for loop
// at even indices we have 5 options and at odd indices we have 4 options.
int countGoodNumbers1(long long n) {
	long long ans = 1;
	int m = 1000000007;
	for (int i = 0; i < n; i++) {
		if (i & 1)ans *= 4;
		else ans *= 5;

		ans %= m;
	}

	return ans;

	// TC --> O(n)
	// The constraints for this question are --> 1 <= n <= 10^15.
	// So, there will be a time limit error.
}


long long Pow(long long x, long long n) {
	if (n == 0)return 1;
	long long ans = Pow(x, n / 2);
	ans *= ans;
	ans %= mod;

	if (n % 2)ans *= x;
	ans %= mod;
	return ans;
}


// we can break down the calculation as -
// good numbers --> 5^(n/2 + n%2) * 4(n/2);
// calculating these using recursive binary exponentiation.
int countGoodNumbers(long long n) {
	int odd = n / 2 + (n % 2);
	int even = n / 2;

	return (Pow(5, even) * Pow(4, odd)) % mod;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	long long n;
	cin >> n;
	cout << countGoodNumbers(n) << endl;
}


