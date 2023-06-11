#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int days, int mid) {
	int n = arr.size();
	int countDays = 1;
	int weight = 0;
	for (int i = 0; i < n; i++) {
		if (weight + arr[i] <= mid)weight += arr[i];
		else {
			countDays++;
			if (countDays > days || arr[i] > mid)
				return false;

			weight = arr[i];
		}
	}
	return true;
}


int minMaximzedCapacity(vector<int> &weights, int days) {
	int n = weights.size();
	int low = 1;
	int sum = 0;
	for (int i = 0; i < n; i++)sum += weights[i];
	int high = sum;
	int res = -1;

	while (low <= high) {
		int mid = (low + high) >> 1;

		if (isPossible(weights, days, mid) == true) {
			res = mid;
			high = mid - 1;
		}

		else low = mid + 1;
	}

	return res;

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

	cout << minMaximzedCapacity(arr, days) << endl;

}

