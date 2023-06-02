#include <bits/stdc++.h>
using namespace std;


int maxFrequency(vector<int> &arr, int k) {
	unordered_map<int, int> map;

	for (int i = 0; i < n; i++) {
		map[arr[i]]++;
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, k, temp;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;
	}
	cin >> k;
	maxFrequency(arr, k);

}