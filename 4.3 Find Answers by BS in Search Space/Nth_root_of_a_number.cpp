#include <bits/stdc++.h>
using namespace std;


// Brute Force solution --> Run a loop until nth root of number is met
long long int NthRoot1(int n, long long int m) {
	int ans = 1;
	if (n == 1 || m == 1)return m;

	for (int i = 1; i < m; i++)  {
		long long int num = 1;

		for (int j = 0; j < n; j++) {
			num *= i;
		}

		if (num == m) {
			return i;
		}

		else if (num > m)return -1;
	}

	return -1;

	// TC --> O(sqrt(m) * n);

}


// returns the number^n or (num*num*num....n times)
double multiply(double number, int n) {
	double ans = 1.0;
	for (int i = 1; i <= n; i++) {
		ans = ans * number;
	}
	return ans;
}


// Optimal solution --> Binary Search
long long int NthRoot(int n, int m) {
	int low = 1;
	int high = m;

	if (n == 1 || m == 1)return m;

	while (low <= high) {

		int mid = low + (high - low) / 2;

		if (multiply(mid, n) < m) low = mid + 1;

		else high = mid - 1;
	}

	return ((multiply(low, n) == m) ?  low : -1);

	// TC --> n*log(m)
	// SC --> O(1)
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	long long int n;
	int m;

	cin >> n >> m;
	cout << NthRoot(m, n) << endl;

}

