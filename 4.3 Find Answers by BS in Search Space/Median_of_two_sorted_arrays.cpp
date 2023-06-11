#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution
// Find the union of both arrays and then output the median
double medianOfTwoSortedArrays1(vector<int> &arr1, vector<int> &arr2) {
	int n = arr1.size();
	int m = arr2.size();
	double res;

	vector<int> ans;
	int i = 0, j = 0;

	while (i < n && j < m) {
		if (arr1[i] <= arr2[j]) {
			ans.push_back(arr1[i]);
			i++;
		}

		else {
			ans.push_back(arr2[j]);
			j++;
		}
	}


	while (i < n) {
		ans.push_back(arr1[i]);
		i++;
	}


	while (j < m) {
		ans.push_back(arr2[j]);
		j++;
	}


	if ((n + m) % 2 == 0) {
		double val1 = ans[(n + m) / 2];
		double val2 = ans[(n + m - 1) / 2];

		res = (val1 + val2) / 2;
	}

	else res = ans[(n + m ) / 2];

	return res;

	// TC --> O(n + m)
	// SC --> O(n+m)
}



// Better Solution --> optimised naive Approach
// Do not make an array, just keep track of the counter
// when counter reaches median pos , calculate the median and return.
double medianOfTwoSortedArrays2(vector<int> &arr1, vector < int> &arr2) {
	int n = arr1.size();
	int m = arr2.size();
	int counter = -1;
	double val1, val2, ans = -1;
	int i = 0, j = 0;

	while (counter <= (n + m) / 2) {

		if ( (i != n) && ( j == m  || arr1[i] <= arr2[j])) {
			ans = arr1[i];
			i++;
		}

		else {
			ans = arr2[j];
			j++;
		}

		counter++;
		if (counter == ((n + m) / 2) - 1) val1 = ans;
		if (counter == (n + m) / 2) {
			val2 = ans;
			break;
		}

	}

	cout << val1 << " " << val2 << endl;
	if ((n + m) % 2 == 1)return val2;
	return (val1 + val2) / 2;

	// TC --> O(n+m)
	// SC --> O(1)
}


// Optimal Solution --> using Binary Search
double medianOfTwoSortedArrays(vector<int> &nums1, vector<int> &nums2) {
	int n = nums1.size();
	int m = nums2.size();
	if (n > m)return medianOfTwoSortedArrays(nums2 , nums1);

	int low = 0, high = n;

	while (low <= high) {
		int cut1 = (low + high) >> 1;
		int cut2 = (n + m + 1) / 2 - cut1 ;

		int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
		int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
		int r1 = (cut1 == n) ? INT_MAX : nums1[cut1];
		int r2 = (cut2 == m) ? INT_MAX : nums2[cut2];

		if (l1 <= r2 && l2 <= r1) {
			if ((m + n) % 2 != 0)
				return max(l1, l2);
			else
				return (max(l1, l2) + min(r1, r2)) / 2.0;
		}

		else if (l1 > r2) {
			high = cut1 - 1;
		}

		else low = cut1 + 1;

	}

	return 0.0;
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
	vector<int>arr1;
	vector<int>arr2;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr1.push_back(temp);
	}
	for (int i = 0; i < m; i++) {
		cin >> temp;
		arr2.push_back(temp);
	}

	cout << medianOfTwoSortedArrays(arr1, arr2) << endl;


}

