#include <bits/stdc++.h>
using namespace std;



// To find the max sum subarray we are using the same approach as the last question's Optimal solution.
// We are only adding the start and ending indexes of the max sum subarr to the program.
long long printMaxSumSubarray(vector<int> &arr) {
	int n = arr.size();
	int ans_start = -1, ans_end = -1; // max sum subarr position in the arr(ans_start , ans_end).
	long long sum = 0;
	long long maxSum = LONG_MIN;

	int start = 0; // initialising a start index
	for (int i = 0; i < n; i++) {

		sum += arr[i];

		if (sum > maxSum) {
			ans_start = start; // when maxSum is obtained start and end are updated
			ans_end = i; // end will be the current index
			maxSum = sum;
		}

		if (sum < 0) {
			sum = 0;
			start = i + 1;
		}


	}


	// print the maxSum Subarr
	for (int i = ans_start; i <= ans_end; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return maxSum;

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, temp;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	long long ans = printMaxSumSubarray(arr);

	cout << ans << endl;

}