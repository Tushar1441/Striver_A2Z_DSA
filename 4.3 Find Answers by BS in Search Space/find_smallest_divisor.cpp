#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int threshold, int divisor) {
	int curr = 0, j = 0;
	while (j < arr.size()) {
		curr += ceil((double)arr[j] / (double)divisor);

		if (curr > threshold)return false;
		j++;
	}
	return true;
}


int smallestDivisor(vector<int> &nums, int threshold) {
	int low = 1, high = *max_element(nums.begin(), nums.end());
	int ans = INT_MAX;

	int mid;
	while (low <= high) {
		mid = low + ((high - low) / 2);

		if (isPossible(nums, threshold, mid)) {
			high = mid - 1;
		}

		else low = mid + 1;
	}

	return low;

	// TC --> O(n * log(max))  (max -- sum of elements in array)
	// SC --> O(1)
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, days, temp;
	vector<int>arr;
	cin >> n >> days;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	cout << smallestDivisor(arr, days) << endl;

}

