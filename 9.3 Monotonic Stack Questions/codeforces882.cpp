#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k, temp;
	cin >> n >> k;
	vector<int>arr;
	vector<int>differences;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
		if (i > 0) differences.push_back(abs(arr[i] - arr[i - 1]));
	}

	sort(differences.begin(), differences.end());

	long long minDiff = 0;
	for (int i = 0; i < n - k; i++) {
		minDiff += differences[i];
	}

	cout << minDiff << endl;
}


void solve1() {
	long long n, temp ;
	cin >> n;
	vector<long long>arr;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	int maxi = (1 << 30) - 1;

	int curr = maxi;
	for (int i = 0; i < n; i++) {
		curr &= arr[i];
	}

	int res = 0;
	int cur = maxi;

	for (int i = 0; i < n; i++) {
		cur &= arr[i];
		if (cur == 0) {
			res += 1;
			cur = maxi;
		}
	}

	res += (curr > 0);
	cout << res << endl;
}

void solve2() {
	long long n;
	cin >> n;
	long long res = 0;
	vector<long long>arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		res = max(res, arr[i]);
	}

	for (long long i = 0; i < n; i++) {
		long long curr = 0;
		for (long long j = i; j < min(n, i + 256); j++) {
			curr ^= arr[j];
			res = max(res, curr);
		}
	}

	cout << res << endl;
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
		solve1();
	}
}