#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int n,int m, int mid) {
	int pageSum = 0;
	int studentCount = 1;

	for (int i = 0; i < n; i++) {
		pageSum += arr[i];

		if (pageSum > mid) {
			studentCount++;
			pageSum = arr[i];
		}

		if (studentCount > m) {
			return false;
		}

	}

	return true;
}


int allocateBooks(vector<int> &arr, int n, int m) {
	int maxi = INT_MIN;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		maxi = max(maxi, arr[i]);
	}
	int ans = -1;
	int low = maxi;
	int high = sum;

	while (low <= high) {

		int mid = low + (high - low) / 2;

		bool res = isPossible(arr, n, m, mid);

		if (res == true) {
			ans = mid;
			high = mid - 1;
		}

		else low = mid + 1;

	}

	return ans;
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
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	cout << allocateBooks(arr, n, m) << endl;

}