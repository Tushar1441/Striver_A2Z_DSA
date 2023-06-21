#include <bits/stdc++.h>
using namespace std;


int minCoins(vector<int>coins, int n, int v) {
	int ans = 0;
	for (int i = n - 1; i >= 0 ; i--) {
		while (v >= coins[i]) {
			cout << coins[i] << " ";
			v -= coins[i];
			ans++;
		}

		if (v == 0)return ans;
	}

	return ans;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, m, temp;
	cin >> n >> m;

	vector<int>items;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		items.push_back(temp);
	}

	cout <<  minCoins(items, n, m) << endl;

}