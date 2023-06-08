#include <bits/stdc++.h>
using namespace std;


// iterative Binary Search
int binarySearch(vector<int> &arr, int target) {
	int low = 0;
	int high = arr.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == target)return mid;
		else if (arr[mid] < target) low = mid + 1;
		else high = mid - 1;
	}

	return -1;
}

// recursive Binary search
int recursiveBS(vector<int> arr, int low, int high, int target) {
	if (low > high) {
		return -1;
	}

	if (arr[mid] == target)return mid;
	else if (arr[mid] > target)recursiveBS(arr, low, mid - 1, target);
	else recursiveBS(arr, mid + 1, high, target);

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

	int ans = binarySearch(arr, k);
	cout << ans << endl;

}