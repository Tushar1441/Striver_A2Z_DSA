#include <bits/stdc++.h>
using namespace std;

int atmostSumSubarray(vector<int>& nums, int goal) {
	int n = nums.size();

	int res = 0, sum = 0;

	// sliding pointers
	int left = 0, right = 0;

	while (right < n) {
		sum += nums[right];

		while (sum > goal) {
			sum -= nums[left];
			left++;
		}

		res +=  (right - left + 1);
		right++;
	}

	return res;
}


// Optimal Approach --> Using Sliding Window Algorithm
int numSubarraysWithSum(vector<int>& nums, int goal) {
	return atmostSumSubarray(nums, goal) - atmostSumSubarray(nums, goal - 1);
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
	cout << numSubarraysWithSum(arr, k) << endl;
}