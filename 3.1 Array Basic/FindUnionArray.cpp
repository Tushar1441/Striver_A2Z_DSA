#include <bits/stdc++.h>
using namespace std;


// Brute Forced Approach-->
// Using map data structure
vector<int> findUnionArray1(vector<int> &arr1, vector<int> &arr2, int n, int m) {
	map<int , int> mapp;

	// Iterate over both the arrays and store all the elemnts and their frequencies
	// as key value pair in the map.
	for (int i = 0; i < n; i++) {
		mapp[arr1[i]]++;
	}
	for (int i = 0; i < m; i++) {
		mapp[arr2[i]]++;
	}

	// Make a new arr which contains the union elements push all the key values from the map
	// into it
	vector<int> ans;

	for (auto it : mapp) {
		ans.push_back(it.first);
	}

	return ans;

	// TC --> one insertion in a map takes O(logn) time , total elements to be inserted-->(m+n)
	// Final TC --> O((m+n)*log(m+n))
	// SC --> O(n+m) (for map data structure)  + O(n+m) (for returning the answer in an arr)
}



// Optimal Approach
// Using two pointers
vector<int> findUnionArray(vector<int> &arr1, vector<int> &arr2, int n, int m) {
	vector<int> ans;

	int i = 0, j = 0;

	// Iterate through both the arrays at the same time and compare the current iterated
	// element and put the smaller one into the answer array and increment the iterator.
	while (i < n && j < m) {

		if (arr1[i] <= arr2[j]) {
			// Also check if the current smaller element is present in our answer arr or not.
			if (ans.size() == 0 || arr1[i] != ans.back()) {
				ans.push_back(arr1[i]);
			}
			i++;
		}

		else if (arr1[i] > arr2[j]) {
			if (ans.size() == 0 || arr2[j] != ans.back()) {
				ans.push_back(arr2[j]);
			}
			j++;
		}

	}

	// Iterate through the remaining elements of the arrays if any.
	while (i < n) {
		if (ans.size() == 0 || arr1[i] != ans.back()) {
			ans.push_back(arr1[i]);
		}
		i++;
	}

	while (j < m) {
		if (ans.size() == 0 || arr2[j] != ans.back()) {
			ans.push_back(arr2[j]);
		}
		j++;
	}

	return ans;

	// TC --> O(n+m) running a loop on both the arrays
	// SC --> O(1) no extra space required other than the answer arr.
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
	vector<int> arr1(n);
	vector<int> arr2(m);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr1[i] = temp;
	}
	for (int i = 0; i < m; i++) {
		cin >> temp;
		arr2[i] = temp;
	}

	vector<int> arr = findUnionArray(arr1, arr2, n, m);

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}