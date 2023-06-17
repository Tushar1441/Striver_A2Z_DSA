#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int m, int k, int mid) {
	int n = arr.size();
	int countRose = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] <= mid)count++;
		if (count == k) {
			countRose++;
			count = 0;
		}

		else if (arr[i] > mid) {
			count = 0;
		}
	}

	if (countRose < m)return false;
	return true;
}


int minDays (vector<int> &arr, int m, int k) {
	int n = arr.size();
	int low = 1;
	// if the array contains all duplicate elements then the maximum becomes minimum.
	int high = *max_element(arr.begin(), arr.end());
	int res = -1;

	while (low <= high) {
		int mid = (low + high) >> 1;

		// check if it is possible to make m boquets with k adjacant flowers
		// in equal to or less than mid days.
		// if possible it can be our answer.so, store it and move to left.
		if (isPossible(arr, m, k, mid) == true) {
			res = mid;
			high = mid - 1;
		}

		// else we have to take more days so move right.
		else low = mid + 1;
	}

	return res;

	// TC --> O(n * log(max))  (max -- maximum element in array)
	// SC --> O(1)
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, m, k, temp;
	vector<int>arr;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	cout << minDays(arr, m, k) << endl;

}

