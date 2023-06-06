#include <bits/stdc++.h>
using namespace std;




// Brute Force Appproach - checking every pair in the array
vector<int> twoSum1(vector<int> &arr, int target) {
	int n = arr.size();
	vector<int> ans;

	for (int i = 0; i < n - 1; i++) {    // first element..
		for (int j = i + 1; j < n; j++) {   // second element..
			if (arr[i] + arr[j] == target) {
				ans.push_back(i);
				ans.push_back(j);
				return ans;
			}
		}
	}

	return { -1, - 1};
	// TC --> O(n^2) - two nested for loops
	// SC --> O(1) - no extra space required other than ans arr.
}



// Optimal Approach - Using Hashing
vector<int> twoSum(vector<int> &arr, int target) {
	int n = arr.size();
	vector<int> ans;
	map<int, int> hashmap;


	for (int i = 0; i < n ; i++) {

		int rem = target - arr[i];

		// we will check if the other required element(i.e. target-arr[i]) exists in the hashMap
		if (hashmap.find(rem) != hashmap.end()  && i > 0) {
			ans.push_back(hashmap[rem]);
			ans.push_back(i);
			return ans;
		}

		// append the elements and the indexes
		hashmap[arr[i]] = i;
	}

	return { -1, - 1};
	// Time Complexity: O(N), where N = size of the array.
	// The loop runs N times in the worst case and searching in a hashmap takes O(1) generally.
	// Note* --> In worst case ordered map ca take upto O(n) in searching so the TC becomes O(n^2)
	//  in such cases, we can use unordered map which take O(logn) time in every search.

	// SC --> O(n) using hashmap
}



// Optimal Approach --> Without using map data structure

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, k, temp;
	cin >> n >> k;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	vector<int> ans = twoSum(arr, k);
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << endl;

}