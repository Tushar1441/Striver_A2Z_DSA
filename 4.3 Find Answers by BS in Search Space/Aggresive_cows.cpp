#include <bits/stdc++.h>
using namespace std;


int aggresiveCows(vector<int> &stalls , int k) {
	sort(stalls.begin(), stalls.end());
	int maxi = INT_MIN;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, k, temp;
	cin >> n >> temp;
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	cout << aggresiveCows(arr, k) << endl;


}

