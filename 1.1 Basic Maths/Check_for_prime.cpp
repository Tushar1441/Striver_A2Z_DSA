#include <bits/stdc++.h>
using namespace std;


bool isPrime(int n) {
	// Method 1 - Iterate over all the numbers

	// for (int i = 2; i < n; i++) {
	// 	if (n % i == 0)return false;
	// }
	// return true;

	// Method 2 - Iterate over only sqrt(n) elements

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
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
	int n;
	cin >> n;
	cout << isPrime(n) << endl;
}