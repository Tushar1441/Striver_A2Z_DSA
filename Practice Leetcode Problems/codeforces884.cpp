#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;

	cout << a + b << endl;
}

void solve1() {
	int n;
	cin >> n;

	vector<long long>arr(n);

	arr[0] = 2;
	if (n >= 3)arr[n - 1] = 3;
	arr[n / 2] = 1;

	long long res = 4;
	for (int i = 1; i < n - 1; i++) {
		if (i != n / 2) {
			arr[i] = res;
			res++;
		}
	}


	for (auto &it : arr) {
		cout << it << " ";
	} cout << endl;
}


void solve2() {
	int n, temp;
	cin >> n;
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	long long res1 = 0, res2 = 0;

	for (int i = 0; i < n; i++) {
		if (!(i & 1)  &&  arr[i] > 0)res1 += arr[i];
		else if ((i & 1) && arr[i] > 0)res2 += arr[i];
	}

	long long ans = max(res1, res2);

	if (ans == 0) {
		int maxi = INT_MIN;
		for (int i = 0; i < n; i++) {
			maxi = max(maxi , arr[i]);
		}

		ans = maxi;
	}

	cout << ans << endl;

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
		solve2();
	}
}