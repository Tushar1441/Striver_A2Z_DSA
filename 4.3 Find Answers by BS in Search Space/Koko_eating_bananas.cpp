#include <bits/stdc++.h>
using namespace std;


// Brute force Solution -->
// The solution range lies from 1 to max[arr]. So, Iterate on this range.
// On every iteration, check if it suits the follwing condition-
// (i) The complete array is exhausted
// (ii) The hours are exhausted
int minimumSpeed1(vector<int> &piles, int h) {
	int n = piles.size();
	int maxi = INT_MIN;

	for (int i = 0; i < n; i++) {
		if (maxi < piles[i])maxi = piles[i];
	}

	for (int i = 1; i <= maxi; i++) {
		int hr = 0;
		int  num = i;

		for (int j = 0; j < n; j++) {
			double n = piles[j];
			hr += ceil(n / num);
		}

		if (hr == h)return i;
	}

	return maxi;

	// TC --> O(max[arr] * n)
	// SC --> O(1)
}



// Optimal Solution --> Using Binary Search
int minimumSpeed(vector<int> &piles, int h) {
	int n = piles.size();

	int ans = *max_element(piles.begin(), piles.end());
	int low = 1, high = ans, mid;

	while (low <= high) {

		mid = low + (high - low) / 2;
		long long int hr = 0;

		// for every mid, calculate the hours used
		for (int i = 0; i < n; i++) {
			double num = piles[i];
			hr += ceil(num / mid);
		}

		// if hours used by mid == given hours, it is the answer
		// or if hr < h, it can be our answer.
		if (hr <= h) {
			ans = min(ans, mid);
			high = mid - 1;
		}

		else low = mid + 1;
	}

	return ans;

	// TC --> O( log(max) * n)
	// SC --> O(1)
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, h, temp;
	cin >> n >> h;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	cout << minimumSpeed(arr, h) << endl;

}