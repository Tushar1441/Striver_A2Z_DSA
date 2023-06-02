#include <bits/stdc++.h>
using namespace std;

void frequencies(int arr[], int n) {
	unordered_map<int, int> map;

	for (int i = 0; i < n; i++) {
		map[arr[i]]++;
	}

	for (auto i : map ) {
		cout << i.first << " " << i.second << endl;
	}
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
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	frequencies(arr, n);
}