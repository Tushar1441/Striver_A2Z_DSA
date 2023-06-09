#include <bits/stdc++.h>
using namespace std;


int minDays (vector<int> &arr, int m, int k) {
	int n = arr.size();
	if (n < m * k)return -1;
	int k1 = 0, m1 = 0;
	for (int i = 0; i < n; i++) {
		k1++;
		if (k1 == k) {
			m1++;
			k1 = 0;
		}

		if (m1 == m) {
			return arr[i];
		}
	}

	return -1;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, m, k, temp;
	vector<int>arr;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	cout << minDays(arr, m, k) << endl;

}

