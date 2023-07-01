#include <bits/stdc++.h>
using namespace std;


// Optimal Approach --> Using Sliding Window Algorithm
int characterReplacement(string s, int k) {

	int n = s.size();

	int len = 0, maxi = 0;
	// initialise a unordered map ds.
	unordered_map<char, int>mpp;

	// sliding pointers
	int left = 0, right = 0;

	while (right < n) {
		// update the frequency.
		mpp[s[right]]++;

		maxi = max(maxi, mpp[s[right]]);

		if (right - left + 1 - maxi > k) {
			if (mpp[s[left]] == maxi)maxi -= 1;
			mpp[s[left]]--;
			left++;
		}

		// update the length to current window size if possible.
		len = max(len, right - left + 1);
		right++;
	}

	return len;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	string s;
	int k;
	cin >> s >> k;
	cout << characterReplacement(s, k) << endl;
}