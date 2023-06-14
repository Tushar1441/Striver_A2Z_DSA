#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach -- using bit manipulation, generate all subsets and store them in a set.
void subsetSum1(vector<int> &arr, set<vector<int>>&ans) {
	int n = arr.size();
	for (int i = 0; i < (1 << n); i++) {
		vector<int>temp;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))temp.push_back(arr[j]);
		}
		ans.insert(temp);
	}

	// TC --> O(2^n * n * k) + O(2^n *k) , k is the average length of subsets
	// first part is for the subsets generation and second part is to put the set into a vector.

	// SC--> O(n) + O(2^n * k) + O(2^n *k)

}


// Brute Force Approach -- generate all the subsets by take or not take approach
//  and store them in a set and then move them into a vector.
void subsetSum2(int idx, vector<int>&arr, vector<int> ds, set<vector<int>> &ans) {
	if (idx == arr.size()) {
		sort(ds.begin(), ds.end());
		ans.insert(ds);
		return;
	}


	ds.push_back(arr[idx]);
	subsetSum2(idx + 1, arr, ds, ans);
	ds.pop_back();

	subsetSum2(idx + 1, arr, ds, ans);

	// TC --> O(2^n) +  O(k *log x) x is the number of unique subsets.
	// SC -->  2 *  O(2^n * k)  first time storing all the subsets in the set and then again storing them into
	//  answer list.
}


// Optimal Approach -->
// while not taking a element, just don't only skip the current element but also skip all
// the duplicate elements.
void subsetSum3(int idx, vector<int>&arr, vector<int> ds, vector<vector<int>> &ans) {
	if (idx == arr.size()) {
		ans.push_back(ds);
		return;
	}


	ds.push_back(arr[idx]);
	subsetSum3(idx + 1, arr, ds, ans);
	ds.pop_back();

	int i = idx + 1;
	for (i; i < arr.size(); i++) {
		if (arr[i] == arr[idx])continue;
		else break;
	}

	subsetSum3(i, arr, ds, ans);

	// TC --> O(2^n) +  O(k *log x) x is the number of unique subsets.
	// SC -->  2 *  O(2^n * k)  first time storing all the subsets in the set and then again storing them into
	//  answer list.
}

// Optimal Approach 2 --> Using for loop with recursion
void subsetSum4(int idx, vector<int>&arr, vector<int> ds, vector<vector<int>> &ans) {
	ans.push_back(ds);


	for (int i = idx; i < arr.size(); i++) {
		if (i != idx   && arr[i] == arr[i - 1])continue;
		ds.push_back(arr[i]);
		subsetSum4(i + 1, arr, ds, ans);
		ds.pop_back();
	}



	// TC --> O(2^n) +  O(k *log x) x is the number of unique subsets.
	// SC -->  2 *  O(2^n * k)  first time storing all the subsets in the set and then again storing them into
	//  answer list.
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
	// set<vector<int>> st;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	vector<int>ds;
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;


	subsetSum3(0, arr, ds, ans);


	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}

		cout << endl;
	}
}


