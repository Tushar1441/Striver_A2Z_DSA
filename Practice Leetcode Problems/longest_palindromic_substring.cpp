#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
	int i = 0, j = s.size() - 1;

	while (i < j) {
		if (s[i] != s[j])return false;
		i++; j--;
	}

	return true;
}

// Brute Force Solution --> Generate all substrings and check if they are palindrome
string longestPalindrome(string s) {
	string ans = "";

	for (int i = 0; i < s.size(); i++) {
		string curr = "";
		for (int j = i; j < s.size(); j++) {
			curr += s[j];
			if (isPalindrome(curr) && curr.size() > ans.size()) {
				ans = curr;
			}
		}
	}

	return ans;

	// TC --> O(n^2 * n/2) --> n^2 for two for loops and n/2 to check palindrome
	// SC --> O(1)
}


// Optimal Solution
// For every s[i] in the string, expand towards its left and right and compare the elements
string longestPalindrome1(string s) {
	string res = "";
	int resLength = 0;

	for (int i = 0; i < s.size(); i++) {

		// odd length
		int l = i, r = i;
		while (l >= 0 && r < s.size() && s[l] == s[r]) {
			if (r - l + 1 > resLength) {
				res = s.substr(l, r - l + 1);
				resLength = r - l + 1;
			}
			l--; r++;
		}

		// even length
		l = i; r = i + 1;
		while (l >= 0 && r < s.size() && s[l] == s[r]) {
			if (r - l + 1 > resLength) {
				res = s.substr(l, r - l + 1);
				resLength = r - l + 1;
			}
			l--; r++;
		}
	}

	return res;

	// TC --> O(N^2)
	// SC --> O(1)
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

	cout << longestPalindrome1(s) << endl;

}