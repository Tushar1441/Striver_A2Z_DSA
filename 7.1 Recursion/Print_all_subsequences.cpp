#include <bits/stdc++.h>
using namespace std;


void printAllSubsequences(int idx, int n, vector<int> &ans, vector<int> &arr) {
	if (idx >= n) {
		for (auto it : ans)cout << it << " ";
		cout << endl;
		return;
	}

	// pick the ith element in the subsequence
	ans.push_back(arr[idx]);
	printAllSubsequences(idx + 1, n, ans, arr);

	// not pick the answer element in the subsequence
	ans.pop_back();
	printAllSubsequences(idx + 1, n, ans, arr);


	// TC --> O(2^n) * O(n)  (total recursion calls * printing the answer every time)
	// SC --> O(n)  recursion stack space.
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
	vector<int>ans;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	printAllSubsequences(0, n, ans, arr
	                    );
}


