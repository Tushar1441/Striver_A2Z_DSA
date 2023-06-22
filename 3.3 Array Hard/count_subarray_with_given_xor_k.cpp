#include <bits/stdc++.h>
using namespace std;


// Brute Force approach (Best case)--> Using two nested for loops
int maxCount1(vector<int> &arr, int n, int k) {
	int count = 0;

	for (int i = 0; i < n; i++) {
		long long xor1 = 0;

		for (int j = i; j < n; j++) {
			xor1 ^= arr[j];

			// check for the maxlength
			if (xor1 == k) count++;

		}
	}

	return count;

	// TC --> O(N*2) (running two nested loops both for max n times )
	// SC --> O(1) (no extra space required)
}

int maxCount2(vector<int> &arr){
	int n = arr.size();
	int count = 0;
	int xorr = 0;
	map<int, int>mpp;
	mpp[0]++;

	for (int i = 0; i < n; i++) {
		xorr ^= arr[i];

		int xr = xorr ^ x;

		if (mpp.find(xr) != mpp.end())count += mpp[xr];

		mpp[xorr]++;
	}

	return count;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, temp;
	long long k;
	cin >> n >> k ;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;
	}

	int ans = longestSubarray(arr, k);
	cout << ans << endl;

}