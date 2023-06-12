#include <bits/stdc++.h>
using namespace std;


int minBitFlips(int start, int goal) {
	int n = start, m = goal;
	int flip = 0;

	while (n > 0 || m > 0) {

		if ((n & 1) != (m & 1))flip++;

		n >>= 1;
		m >>= 1;
	}

	return flip;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, m;
	cin >> n >> m;
	cout << minBitFlips(n, m) << endl;
}