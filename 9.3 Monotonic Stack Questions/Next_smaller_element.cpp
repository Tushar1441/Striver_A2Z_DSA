#include <bits/stdc++.h>
using namespace std;


// Optimised Approach --> Using Stack data structure
vector<int> nextSmallerElement(vector<int> nums, int n) {
	// intialise a stack which will calculate the next smaller elements value for all
	// the idx elements for array nums2.
	stack<int>st;

	// answer array that will store all the NSE corresponding all the array indexes
	vector<int>ans(n);

	for (int i = n - 1; i >= 0; i--) {

		while (!st.empty() && st.top() >= nums[i])st.pop();

		if (st.empty()) {
			ans[i] = -1;
		}

		else ans[i] = st.top();

		st.push(nums[i]);
	}

	return ans;

	//TC --> O(N)
	// SC --> O(N)
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
	vector<int>ans = nextSmallerElement(nums1, n);

	for (auto it : ans)cout << it << " ";
	cout << endl;
}