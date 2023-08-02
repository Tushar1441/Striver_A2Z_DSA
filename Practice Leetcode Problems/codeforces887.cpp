#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	long long mini = INT_MAX;

	vector<long long>arr;
	long long a;

	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);

		if (i > 0 && arr[i] < arr[i - 1]) {
			cout << 0 << endl;
			return;
		}
	}

	for (int i = 1; i < n; i++) {
		mini = min(arr[i] - arr[i - 1], mini);
	}

	cout << (mini / 2) + 1 << endl;
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
		solve();
	}
}