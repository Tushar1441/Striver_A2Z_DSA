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


// Better Approach --> Sliding Window Algorithm using Set data structure
int longestSubstring1(string &s) {
	if (s.size() == 0)return 0;
	// store the characters
	unordered_set<int>st;
	int ans = 0;
	int n = s.size();

	int left = 0, right = 0;
	while (right < n) {
		if (st.find(s[right]) != st.end()) {
			while (left < right && st.find(s[right]) != st.end()) {
				st.erase(s[left]);
				left++;
			}
		}

		st.insert(s[right]);
		ans = max(ans, right - left + 1);
		right++;
	}

	return ans;

	// TC --> O(2*n)
	// SC --> O(n)
}



// optimised Approach --> using sliding window algorithm.
// with map data structure

int longestSubstring2(string &s) {
	int n = s.size();

	unordered_map<char, int>mpp;
	int ans = 0;

	int left = 0, right = 0;
	while (right < n) {

		if (mpp.find(s[right]) != mpp.end()) {
			left = max(mpp[s[right]] + 1, left);
		}

		mpp[s[right]] = right;

		ans = max(ans, right - left + 1);
		right++;
	}

	return ans;

	// TC --> O(N)

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

	int n = longestSubstring2(s);
	cout << n << endl;
}