#include <bits/stdc++.h>
using namespace std;


bool compare(string &curr, string &prev) {
	// there must be only one extra element in the current string.
	if (curr.size() != prev.size() + 1)return false;

	// now check the order/sequence of the elements int the strings.
	int first = 0;
	int second = 0;

	while (first < curr.size() && second < prev.size()) {
		if (curr[first] == prev[second]) {
			first++;
		}
		first++;
	}

	// at the end check if both the arrays are completely traversed
	if (first == curr.size() && second == prev.size())return true;
	return false;
}

bool comp(string &s1, string &s2) {
	return s1.size() < s2.size();
}

int longestStringChain(vector<int>&words) {
	int n = words.size();

	sort(words.begin(), words.end(), comp);

	// initialise a dp array with value of 1.
	// it stores the maximum length of the longest string chain up till that particular index.
	vector<int>dp(n, 1);

	int maxi = 1;
	// update the dp array for every index.
	for (int i = 0; i < n; i++) {
		for (int prev = 0; prev < i; prev++) {
			// compare the current and the previous string.
			if (compare(words[i] , words[prev]) && dp[i] < 1 + dp[prev]) {
				dp[i] =  1 + dp[prev];
			}
		}

		if (dp[i] > maxi)maxi = dp[i];
	}

	return maxi;

	// TC --> O(n^2)
	// SC --> O(n)
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
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	cout << printLIS(arr) << endl;
}