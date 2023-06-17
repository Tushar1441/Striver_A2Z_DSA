#include <bits/stdc++.h>
using namespace std;

// Solution 1 --> using for loop
double myPow(double x, int n) {
	int neg = 0;
	if (n < 0)neg = 1;
	n = abs(n);
	double ans = 1.0;
	for (int i = 0; i < n; i++) {
		ans *= x;
	}

	if (neg == 1) {
		return (1.0 / ans);
	}

	return ans;

	// TC --> O(n)
}


// Solution 2 -- Using Binary Exponentiation
double myPow2(double x, int n) {
	double ans = 1.0;
	long nn = n;
	nn = abs(nn);

	while (nn > 0) {
		// If n is odd (x^n) can be written as x* (x)^n-1, so now (n-1) is even.
		if (nn & 1) {
			ans = ans * x;
			nn -= 1;
		}

		// If n is even (x^n) can be written as  (x^2)^n/2. As we can see that
		// computation steps were reduced from n to n/2 in just one step.
		else {
			x = x * x;
			nn /= 2;
		}
	}

	if (n < 0) ans = 1.0 / ans;
	return ans;
	// TC --> O(log n)
}


double myPow3(double x, int n, double ans) {
	if (n == 0)return ans;

	if (n & 1) return myPow3(x, n - 1, ans * x);
	else return myPow3(x * x, n / 2, ans);
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	double x;
	int n;
	cin >> x >> n;

	long nn = n;

	if (nn < 0) {
		// checking the int_max overflow while converting the neg value to pos.
		if (nn == INT_MIN)nn = -1 * (nn + 1);
		else nn = -1 * nn;
	}

	// calculating x^n
	double ans = myPow3(x, nn, 1.0);

	// if n is neg then the ans will be 1/x^n i.e. 1/ans.
	if (n < 0)ans = 1 / ans;

	// we subtracted 1 operation for n = INT_MIN.
	// so doing it manually.
	if (n == INT_MIN)ans *= 1.0 / x;
	cout << ans << endl;;
}


