#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach --> Using Two For loops
int sumSubarrayMins(vector<int>&nums) {
	int n = nums.size();
	int res = 0;

	for (int i = 0; i < n; i++) {
		int mini = INT_MAX;
		for (int j = i; j < n; j++) {
			if (nums[j] < mini) {
				mini = nums[j];
			}
			res += mini;
		}
	}

	return res;

	// TC --> O(N^2)
	// SC --> O(1)
}


// Optimal Solution
// Approach --> Find the number of times an element is
// minimum in all the subarrays it appeared.
// we will use next smaller to right and next smaller to left pattern.
int sumSubarrayMins1(vector<int>&nums) {
	int n = nums.size();

	vector<int>nsr(n);
	vector<int>nsl(n);

	stack<int>st;

	for (int i = 0; i < n; i++) {
		while (!st.empty() && nums[st.top()] >= nums[i]) {
			st.pop();
		}

		if (st.empty())nsl[i] = -1;
		else {
			nsl[i] = st.top();
		}

		st.push(i);
	}

	while (!st.empty())st.pop();

	for (int i = n - 1; i >= 0 ; i--) {
		while (!st.empty() && nums[st.top()] > nums[i]) {
			st.pop();
		}

		if (st.empty())nsr[i] = n;
		else {
			nsr[i] = st.top();
		}

		st.push(i);
	}

	long long sum = 0;

	for (long long i = 0; i < n; i++) {
		sum = (sum + nums[i] * (nsr[i] - i) * (i - nsl[i])) % mod ;
	}

	return sum;
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
	vector<int>nums1;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		nums1.push_back(temp);
	}
	cout << sumSubarrayMins1(nums1) << endl;
}
