#include <bits/stdc++.h>
using namespace std;

// Optimised Approach --> Using Monotone Stack
// Approach --> Find the index of the next greater element to left for every element.
vector<int> calculateSpan(vector<int>arr, int n) {
	vector<int> ans(n);

	stack<int>st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && arr[st.top()] < arr[i]) {
			st.pop();
		}

		if (st.empty()) ans[i]  = i + 1;
		else {
			ans[i] = i - st.top();
		}

		st.push(i);
	}

	return ans;
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
	vector<int> ans = calculateSpan(nums1, n);

	for (auto it : ans) {
		cout << it << " ";
	} cout << endl;
}
