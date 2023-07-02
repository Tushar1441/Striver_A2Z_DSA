#include <bits/stdc++.h>
using namespace std;



// Optimised Approach --> Using Stack data structure
vector<int> nextGreaterElement(vector<int> nums1, vector<int> nums2) {
	int n = nums1.size();
	int m = nums2.size();

	// intialise a stack which will calculate the next greater elements value for all
	// the idx elements for array nums2.
	stack<int>st;
	// push the last element

	// initialise a map ds to store all the values and the next greater elements.
	unordered_map<int, int>mpp;

	for (int i = m - 1; i >= 0; i--) {

		while (!st.empty() && st.top() <= nums2[i])st.pop();

		if (st.empty()) {
			mpp[nums2[i]] = -1;
		}
		else mpp[nums2[i]] = st.top();

		st.push(nums2[i]);
	}

	vector<int>ans;
	for (int i = 0; i < n; i++) {
		ans.push_back(mpp[nums1[i]]);
	}

	return ans;

	// TC --> O(2*m) + O(n)
	// SC --> O(n) + O(m) + O(k), where k is the max number of the elements present
	// in the stack at any time.
	// It can also be written as -> O(2*n) + O(m)
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
	vector<int>nums1, nums2;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		nums1.push_back(temp);
	}

	for (int i = 0; i < m; i++) {
		cin >> temp;
		nums2.push_back(temp);
	}

	vector<int>ans = nextGreaterElement(nums1, nums2);

	for (auto it : ans)cout << it << " ";
	cout << endl;
}