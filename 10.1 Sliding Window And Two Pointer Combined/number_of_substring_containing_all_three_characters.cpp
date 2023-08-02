#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach -> generate all the subarrays
int numberOfSubStrings1(string s) {
	int n = s.size();
	int res = 0;

	for (int i = 0; i < n; i++) {
		set<char>st;
		for (int j = i; j < n; j++) {
			st.insert(s[j]);
			if (st.size() == 3)res++;
		}
	}

	return res;
	// TC --> O(n^2)
}

int solve(string s, int k) {
	int n = s.size();
	unordered_map<char, int>mpp;

	int res = 0, left = 0, right = 0;

	while (right < n) {
		mpp[s[right]]++;

		while (mpp.size() > k) {
			mpp[s[left]]--;
			if (mpp[s[left]] == 0)mpp.erase(s[left]);
			left++;
		}

		res += (right - left + 1);
		right++;
	}

	return res;
}


int numberOfSubStrings2(string s) {
	int n = s.size();
	int mpp[3] = {};
	int res = 0, left = 0, right = 0;

	while (right < n) {
		mpp[s[right] - 'a']++;

		while (mpp[0] && mpp[1] && mpp[2]) {
			mpp[s[left] - 'a']--;
			left++;
		}

		res += left;
		right++;
	}

	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	string s;
	cin >> s;

	cout << numberOfSubStrings(s) << endl;
}