#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach --> Using power set, geerate all the subsets
void subsetSum1(vector<int> &arr, vectot<int> &ans) {

	for (int i = 0; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if ( i &= (1 << j))sum += arr[j];
		}

		ans.push_back(sum);
	}

	return;

	// TC --> O(2^n * n);
	// SC --> O(2^n);
}



// Optimal Solution --> pick or not pick the element
void subsetSums(int idx, vector<int>&arr, vector<int>&ans, int sum) {
	if (idx == arr.size()) {
		ans.push_back(sum);
		return;
	}

	subsetSums(idx + 1, arr, ans, sum);

	subsetSums(idx + 1, arr, ans, sum + arr[idx]);


	// TC --> O(2^n)
	// SC --> O(2^n)

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, temp;
	cin >> n ;
	vector<int>arr;
	vector<int>ans;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	subsetSums(0, arr, ans, 0);

	for (auto it : ans)cout << it << " ";
	cout << endl;
}


