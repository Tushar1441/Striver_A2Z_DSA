#include <bits/stdc++.h>
using namespace std;


// Brute Force solution --> Run a loop until floor sqaure root of number is met
long long int squareRoot1(long long int n) {
	for (int i = 1; i < n; i++) {
		if (i * i > n) {
			return i - 1;
		}
	}

	return 1;

	// TC --> O(sqrt(n));
}


// Optimal solution --> Binary Search
long long int squareRoot(long long int n) {
	long long int low = 1;
	long long int high = n;

	while (low <= high) {
		long long int mid = low + (high - low) / 2;

		if (mid * mid == n)return mid;

		if (mid * mid <= n) {
			low = mid + 1;
		}

		else {
			high = mid - 1;
		}
	}

	return low - 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	long long int n;
	cin >> n;
	cout << squareRoot(n) << endl;

}