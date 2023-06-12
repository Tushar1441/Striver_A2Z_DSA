#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach -- Using three nested loops
vector<vector<int>> zeroSum1(vector<int> &arr) {
	int n = arr.size();
	vector<vector<int>> ans;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (arr[i] + arr[j] + arr[k] == 0) {
					ans.push_back({arr[i], arr[j], arr[k]});
				}
			}
		}
	}

	return ans;

	// TC --> O(n^3)
	// SC --> O(3*k) k is the number of triplets
}



// Optimal Approach --> Taking one element as starting point and do binary search
// for the rest of the two elements
vector<vector<int>> zeroSum(vector<int> &arr) {
	int n = arr.size();
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
	for (int i = 0; i < n - 2; i++) {
		if (i == 0 || ((i > 0) && (arr[i] != arr[i - 1]))) {
			int lo = i + 1, high = arr.size() - 1, sum = 0 - arr[i];

			while (lo < high) {
				if (arr[lo] + arr[high] == sum) {
					ans.push_back({arr[i], arr[lo], arr[high]});

					while (lo < high && arr[lo] == arr[lo + 1]) lo++;
					while (lo < high && arr[high] == arr[high - 1]) high--;

					lo++; high--;
				}

				else if (arr[lo] + arr[high] < sum)lo++;
				else high--;
			}
		}
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
	int n, temp;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	vector<vector<int>> ans = zeroSum(arr);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[0].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}