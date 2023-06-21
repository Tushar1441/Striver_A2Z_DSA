#include <bits/stdc++.h>
using namespace std;


int maxDifference(vector<int>arr, int n) {
	int ans = 0 ;
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n / 2; i++) {
		ans += abs(arr[i] - arr[n - i - 1]);
	}
	return ans;
}


void maxSum(int n, vector<int>&arr) {
	long long sum = 0;
	long long operation = 0;
	int i = 0;
	for (int i = 0; i < n; i++)sum += abs(arr[i]);

	while (i < n) {

		if (arr[i] < 0 ) {
			operation++;
			while (arr[i] <= 0)i++;
		}

		i++;
	}

	cout << sum << " " << operation << endl;

}

void sumInBinaryTree(long long int n) {
	long long int ans = 0;

	while (n) {
		ans += n;
		n >>= 1;
	}

	cout << ans << endl;
}

void dfs(int node, int parent, vector<vector<int>>& graph, int& leaf_count) {
	if (graph[node].size() == 1 && parent != -1) {
		leaf_count++;
	}
	for (int neighbor : graph[node]) {
		if (neighbor != parent) {
			dfs(neighbor, node, graph, leaf_count);
		}
	}
}

void solve() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> graph(n + 1);
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		int q;
		cin >> q;

		while (q--) {
			int x, y;
			cin >> x >> y;

			int leaf_count_x = 0, leaf_count_y = 0;
			dfs(x, -1, graph, leaf_count_x);
			dfs(y, -1, graph, leaf_count_y);

			long long count = (long long)leaf_count_x * leaf_count_y;
			cout << count << endl;
		}
	}
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	solve();
}