#include <bits/stdc++.h>
using namespace std;

// Problem Link -> https://leetcode.com/problems/minimum-window-substring/



// two pointer acquire and release strategy (Sliding window)
// we will make two frequency vectors
string minWindow(string s, string t) {
	int freq[58] = { 0 };
	for (char c : t)
	{
		freq[c - 'A']++;
	}

	// now make a freq vector for the string
	int curr[58] = { 0 };

	// two pointers
	int r = 0;	// acquire pointer
	int l = 0;	// release pointer

	int rmc = t.length();	// required match count
	int cmc = 0;	// current match count

	int n = s.length();
	int anslen = 0;

	// answer string left and right pointers
	int al = -1;
	int ar = -1;

	while (r < n)
	{
		// acquire
		curr[s[r] - 'A']++;
		// increase the match count if freq of s[r] in curr is less than in freq array.
		if (curr[s[r] - 'A'] <= freq[s[r] - 'A']) cmc++;

		// if at any point cmc becomes equals to rmc, then we need to collect the answer
		// and then release some characters from the start until they become unequal again.
		while (l <= r && rmc == cmc)
		{
			// collect the answer if less than previous ans
			if (anslen == 0 || anslen > r - l + 1)
			{
				anslen = r - l + 1;
				al = l;
				ar = r;
			}

			// release the char
			curr[s[l] - 'A']--;
			// check if cmc decreases or not
			if (curr[s[l] - 'A'] < freq[s[l] - 'A']) cmc--;

			// shift the left pointer
			l++;
		}

		r++;
	}

	string ans = "";
	if (ar != -1)
	{
		ans = s.substr(al, ar - al + 1);
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
	string s, t;
	cin >> s >> t;

	cout << minWindow(s, t) << endl;
}