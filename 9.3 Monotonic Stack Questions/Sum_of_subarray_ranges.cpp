#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

// Brute Force Solution -> Using two for loops
// traverse all the subarrays and store their min and max elements.
long long subarrayRanges(vector<int>nums) {
	long long sum = 0;
	int n = nums.size();
	for (int i = 0; i < n; i++) {
		int mini = INT_MAX;
		int maxi = INT_MIN;
		for (int j = i; j < n; j++) {
			mini = min(mini, nums[j]);
			maxi = max(maxi, nums[j]);
			sum += (maxi - mini);
		}
	}

	return sum;

	// TC --> O(n^2)
}


int sumSubarrayMins(vector<int>&nums) {
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

int sumSubarrayMaxs(vector<int>&nums) {
	int n = nums.size();

	vector<int>ngr(n);
	vector<int>ngl(n);

	stack<int>st;

	for (int i = 0; i < n; i++) {
		while (!st.empty() && nums[st.top()] <= nums[i]) {
			st.pop();
		}

		if (st.empty())ngl[i] = -1;
		else {
			ngl[i] = st.top();
		}

		st.push(i);
	}

	while (!st.empty())st.pop();

	for (int i = n - 1; i >= 0 ; i--) {
		while (!st.empty() && nums[st.top()] < nums[i]) {
			st.pop();
		}

		if (st.empty())ngr[i] = n;
		else {
			ngr[i] = st.top();
		}

		st.push(i);
	}

	long long sum = 0;

	for (long long i = 0; i < n; i++) {
		sum = (sum + nums[i] * (ngr[i] - i) * (i - ngl[i])) % mod ;
	}

	return sum;
}

long long subarrayRanges1(vector<int>nums) {

	long long sumMaximum = sumSubarrayMaxs(nums);
	long long sumMinimum = sumSubarrayMins(nums);

	return (sumMaximum - sumMinimum);
	// TC --> O(n^2)
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
	vector<int>nums;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		nums.push_back(temp);
	}

	cout << subarrayRanges1(nums) << endl;
}
