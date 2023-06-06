#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach --> Check all the possibilities
int maxPosDifference1(vector<int> &arr) {
	int n = arr.size();
	int maxi = INT_MIN;
	for (int i = 0; i < n - 1; i++) { // Buying Index
		for (int j = i + 1; j < n; j++) { // Selling Index
			maxi = max(maxi, arr[j] - arr[i]);
		}
	}

	return (maxi > 0 ? maxi : 0);
}


// Optimal Solution --> Two Pointer Approach
// Keeping track of the min stock price from the left
int maxPosDifference(vector<int> &arr) {
	int n = arr.size();
	int maxi = 0;
	int minPrice = INT_MAX;

	for (int i = 0; i < n; i++) {
		minPrice = min(minPrice , arr[i]); // Updating the min stock price
		maxi = max(maxi , arr[i] - minPrice); // Updating the max Profit
	}

	return maxi;

	// TC --> O(n)
	// SC --> O(1)
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, temp;
	cin >> n;
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	int ans = maxPosDifference(arr);
	cout << ans << endl;

}