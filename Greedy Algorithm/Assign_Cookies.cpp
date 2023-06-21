#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>&g, vector<int>&s) {
	int i = s.size() - 1, j = g.size() - 1, ans = 0;
	sort(s.begin(), s.end());
	sort(g.begin(), g.end());


	while ( i >= 0 && j >= 0 ) {
		if (s[i] >= g[j]) {
			i--; ans++;
		}
		j--;
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

	vector<int>arr1;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr1.push_back(temp);
	}

	vector<int>arr2;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		arr2.push_back(temp);
	}

	cout << findContentChildren(arr1, arr2) << endl;

}