#include <bits/stdc++.h>
using namespace std;

// Brute Force Appproach
int KthElementInTwoSortedArrays1(vector<int> &arr1, vector<int> &arr2, int k) {
	int n = arr1.size();
	int m = arr2.size();
	int i = 0, j = 0, ans;
	int counter = 0;

	while (counter <= k) {

		if (counter == k) {
			return ans;
		}

		if ( (i != n) && ( j == m || arr1[i] <= arr2[j])) {
			ans = arr1[i];
			i++;
		}

		else {
			ans = arr2[j];
			j++;
		}
		counter++;

	}

	return -1;
}


// Optimal Approach --> using Binary Search
int KthElementInTwoSortedArrays(vector<int> &arr1, vector<int> &arr2, int k) {
	int n = arr1.size();
	int m = arr2.size();
	if (n > m) {
		return KthElementInTwoSortedArrays(arr2, arr1, k);
	}
	int low = 0, high = min(n, k);

	while (low <= high) {
		int cut1 = (low + high) >> 1;
		int cut2 = k - cut1;

		int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
		int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
		int r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
		int r2 = (cut2 == m) ? INT_MAX : arr2[cut2];

		if (l1 <= r2 && l2 <= r1) {
			return max(l1, l2);
		}

		else if (l1 > r2) high = cut1 - 1;
		else low = cut1 + 1;
	}

	return -1;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, m, k, temp;
	cin >> n >> m >> k;
	vector<int> arr1;
	vector<int> arr2;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr1.push_back(temp);
	}

	for (int i = 0; i < m; i++) {
		cin >> temp;
		arr2.push_back(temp);
	}


	int ans = KthElementInTwoSortedArrays(arr1, arr2, k);
	cout << ans << endl;
}