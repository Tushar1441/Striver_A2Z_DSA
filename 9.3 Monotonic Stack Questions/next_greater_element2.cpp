#include <bits/stdc++.h>
using namespace std;


// Brute Force Solution --> Using Two for loops
vector<int> nextGreaterElements(vector<int>& nums)
{
	int n = nums.size();
	vector<int> arr;

	for (int i = 0; i < n; i++) // starting index
	{
		// next greater element
		int element = -1;
		for (int j = (i + 1) % n; i != j; j = (j + 1) % n)
		{
			if (nums[i] < nums[j])
			{
				element = nums[j];
				break;
			}
		}
		arr.push_back(element);
	}
	return arr;

	// TC --> O(n^2)
}

// Optimised Solution Using Stack data structure
vector<int> nextGreaterElements1(vector<int>& nums) {
	int n = nums.size();
	stack<int> st;
	vector<int> ans(n);
	for (int i = n * 2 - 1; i >= 0; i--) {
		while (!st.empty() && st.top() <= nums[i % n]) {
			st.pop();
		}
		if (i < n) {
			if (!st.empty()) {
				ans[i] = st.top();
			}
			else {
				ans[i] = -1;
			}
		}
		st.push(nums[i % n]);
	}
	return ans;

	// TC --> O(2*n)
	// SC --> O(n) + O(k) -> for answer array and for stack space.
}





int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, m, temp;
	cin >> n;
	vector<int>nums1;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		nums1.push_back(temp);
	}
	vector<int>ans = nextGreaterElements(nums1);

	for (auto it : ans)cout << it << " ";
	cout << endl;
}