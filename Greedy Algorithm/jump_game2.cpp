#include <bits/stdc++.h>
using namespace std;

// Brute Force --> Try out all the possible jumps
// and find the min from them using recursion
// The recursion solution can be further optimized using DP.
// TC --> O(n^2) using DP



// Optimal Solution --> Greedy Approach
// calculate the range of the first element and then check in the range
// what is the farthest possible index.
// Then calculate the range of that range jumps and so on.

// The answer will be how many times we are changing the range.
int jump(vector<int>&arr) {
	int n = arr.size();
	// intialise first range from l to r i.e. the 0th index.
	int l = 0, r = 0;
	int ans = 0;

	//until right reaches n-1
	while (r < n - 1) {
		// max possible jump index
		int farthest = 0;

		while (l <= r) {
			farthest = max(farthest , l + arr[l]);
			l++;
		}

		// update the range to the farthest
		r = farthest;

		//
		ans++;
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