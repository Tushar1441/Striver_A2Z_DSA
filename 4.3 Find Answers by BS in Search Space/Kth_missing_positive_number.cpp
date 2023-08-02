#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution
int KthMissingPositiveIntegar(vector<int> &arr , int k) {
	int n = arr.size(), count = 0;
	int last = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] != last + 1) {
			count += (arr[i] - last - 1);
			last = arr[i];
		}

		else last++;

		if (count >= k) {
			return (arr[i] - (count - k + 1));
		}
	}

	return arr[n - 1] + (k - count);
	// TC --> O(n)
}


int KthMissingPositiveIntegar1(vector<int>&arr, int k) {
	int n = arr.size();
	int curr = 1;
	int j = 0;

	while (j < n) {

		if (arr[j] == curr) j++;
		else k--;

		if (k == 0)return curr;
		curr++;
	}

	return curr + k;
}



// Optimal Solution -- using Binary Search
int KthMissingPositiveIntegar2(vector<int> &arr, int k) {

	int n = arr.size();
	int low = 0, high = n - 1;

	while (low <= high) {

		int mid = (low + high) >> 1;
		int missing = arr[mid] - (mid + 1);

		if (missing < k) low = mid + 1;
		else high = mid - 1;
	}

	// or return low + k;
	return high + 1 + k;
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, k, temp;
	cin >> n >> k;
	vector<int>arr;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	cout << KthMissingPositiveIntegar2(arr, k) << endl;


}

