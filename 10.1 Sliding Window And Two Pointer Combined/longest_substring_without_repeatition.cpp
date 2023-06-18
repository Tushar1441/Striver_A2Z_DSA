#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach --> Using Hashset or Hashmap.
// Put a pointer in the starting char and then iterate through the rest of the string
// storing each char occurence in the hashmap/set.
// If element was already present, then break the loop.
// That will be the longest substring without repeating chars starting with that character.
int longestSubstring(string s) {

	if (s.size() == 0)return 0;
	int ans = INT_MIN; // max length

	// Iterating a loop for the first char of the longest substring.
	for (int i = 0; i < s.size(); i++) {

		// we can use a map also
		// map<char, int>mpp;
		// mpp[s[i]]++;
		int cnt = 0;
		unordered_set<int>st;
		for (int j = i; j < s.size(); j++) {
			// if element already present in set then break the loop.
			if (st.find(s[j]) != st.end()) {
				break;
			}
			cnt++;
			st.insert(s[j]);
		}

		ans = max(ans, cnt);
	}

	return ans;

	// TC --> O(n^2)
	// SC --> O(n)
}



// optimised Approach --> using two pointer approach.

int longestSubstring(string &s) {
	vector<int>mapp(256, 0);

	int ans = 0;
	int left = 0, right = 0;

	while (right < s.size() ) {

		if (s[right] != -1) {

		}

		ans = max(ans, right - left + 1);
		right++;
	}

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

	int n = longestSubstring(s);
	cout << n << endl;
}