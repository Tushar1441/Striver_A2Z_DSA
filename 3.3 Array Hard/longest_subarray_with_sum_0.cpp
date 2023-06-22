#include <bits/stdc++.h>
using namespace std;



// brute force approach --> try all the subarray sum
// this approach can also be done with 3 for loops
// but we are doing this only with two loops.
int maxLength1(vector<int>arr) {
	int n = arr.size();
	int maxLength = -1;

	for (int i = 0; i < n; i++) {
		if (arr[i] == 0)maxLength = max(maxLength, 1);
		int sum = arr[i];
		for (int j = i + 1; j < n; j++) {
			sum += arr[j];
			if (sum == 0) {
				maxLength = max(maxLength, j - i + 1);
			}
		}
	}
	return maxLength;
	// TC --> O(n^2)
}



// Optimised Approach -- Using Hash Map
// store the prefix sum of all the elements.
// if any prefix sum is encountered again in the array,
// then it means the sum of all the elements in between accounts to zero.
int maxLength(vector<int>arr) {

	// map will store prefixSum and indexes
	unordered_map<int , int>mpp;

	// initialise prefix sum to 0
	long long sum = 0;

	// answer variable
	int maxi = 0;

	for (int i = 0; i < n; i++) {
		sum += arr[i];

		if (sum == 0)maxi = i + 1;

		else {
			if (mpp.find(sum) != mpp.end()) {
				maxi = max(maxi, i - mpp[sum]);
			}

			else {
				mpp[sum] = i;
			}
		}
	}

	return maxi;

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

	cout << maxLength(arr) << endl;
}