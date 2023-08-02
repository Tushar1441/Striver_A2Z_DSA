#include <bits/stdc++.h>
using namespace std;
// This problem is exactly similar to the painter partition problem.
// So, the code is also same for both the problems

bool isValid(vector<int> arr, int n, int k, int mid) {
	int subarrayCount = 1;
	int sum = 0;

	for (int i = 0; i < n ; i++) {

		if (sum + arr[i] <= mid) {
			sum += arr[i];
		}
		else {
			subarrayCount++;
			sum = arr[i];
		}

		if (subarrayCount > k)return 0;
	}

	return 1;
}


int splitArray(vector<int> &nums , int k) {
	int n = nums.size();

	int maxi = 0, sum = 0;

	for (auto &it : nums) {
		sum += it;
		maxi = max(maxi, it);
	}

	int low = maxi, high = sum;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (isValid(nums, n, k, mid) )high = mid - 1;
		else low = mid + 1;
	}

	return low;
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

	cout << splitArray(arr, k) << endl;


}

