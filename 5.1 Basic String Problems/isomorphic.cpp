#include <bits/stdc++.h>
using namespace std;


bool isIsomorphic(string &s, string &t) {
	// Check if the lengths of the two strings are not equal
	if (s.size() != t.size())return false;

	// Initialize two unordered maps to keep track of character
	// mappings between the two strings
	unordered_map<char, char>mpp1;
	unordered_map<char, char>mpp2;

	// Iterate through the two input strings simultaneously
	for (int i = 0; i < s.size(); i++) {


		// If the current character of s and t is not already mapped, add it to the maps
		if (mpp1.count(s[i]) == 0  && mpp2.count(t[i]) == 0) {
			mpp1[s[i]] = t[i];
			mpp2[t[i]] = s[i];
		}

		// If sChar is already mapped but not to tChar,
		// or if tChar is already mapped but not to sChar,
		// then the strings are not isomorphic
		else if (mpp1.count(s[i]) > 0 && mpp1[s[i]] != t[i]) {
			return false;
		}
		else if (mpp2.count(t[i]) > 0 && mpp2[t[i]] != s[i]) {
			return false;
		}
	}

	// If the function reaches this point without returning false in the loop,
	// then the two strings are isomorphic
	return true;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	string s, t;
	cin >> s >> t;

	cout << isIsomorphic(s, t) << endl;

}

