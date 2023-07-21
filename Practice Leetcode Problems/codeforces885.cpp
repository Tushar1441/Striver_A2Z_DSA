#include <bits/stdc++.h>
using namespace std;



void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	int x, y;
	cin >> x >> y;

	bool flag = true;

	for (int j = 0; j < k; j++) {
		int a, b;
		cin >> a >> b;
		int d = abs(a - x) + abs(b - y);

		if (d % 2 == 0) {
			flag = false;
		}
	}

	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;

}

void solve1() {
	int n, k;
	cin >> n >> k;

	vector<vector<int>>arr(n + 1, vector<int>(n + 1, 0));
	int a[n + 1] = {0};

	int x;
	for (int i = 1 ; i <= n ; i++) {
		cin >> x;
		arr[x].push_back(i - a[x] - 1);
		a[x] = i ;
	}

	int mini = 1e9 ;
	for (int i = 1 ; i <= k ; i++) {
		arr[i].push_back(n - a[i]);
		sort(arr[i].begin(), arr[i].end(), greater<int>());

		int res = arr[i][0] / 2 ;
		if (arr[i].size() >= 2) res = max(res, arr[i][1]);

		mini = min(mini, res);
	}
	cout << mini << endl;
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

