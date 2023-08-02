#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach --> generate all the substrings and check for the highest and the lowest
// frequencies for every substring and add the result to the answer
int beautySum(string s) {
	int res = 0;
	int n = s.size();

	for (int i = 0; i < n; i++) {

		unordered_map<char, int>mpp;
		for (int j = i; j < n; j++) {
			mpp[s[j]]++;
			int leastfreq = INT_MAX, maxfreq = 0;

			// this loop runs for max 26 times so it can be considered as constant.
			for (auto c : mpp) {
				leastfreq = min(leastfreq, c.second);
				maxfreq = max(maxfreq, c.second);
			}

			res += (maxfreq - leastfreq);
		}
	}

	return res;

	// TC --> O(n^2 *(26)) in case of string
	// but if an array of numbers was given then it would be n^3.

	// SC --> O(n)
}



// if we want to eliminate the third loop we have to use another data structure
// to directly pick up the most and least frequencies without traversing throughout
// the map
int beautySum1(string s) {
	int n = s.length(), res = 0;

	for (int i = 0; i < n; i++) {

		unordered_map<char, int>mpp;
		multiset<int>st;

		for (int j = i; j < n; j++) {
			// if a character's frequency is already present in the set,
			// then first remove it and then insert the new frequency otherwise
			// directly insert it.

			if (mpp.find(s[j]) != mpp.end()) {
				// there can be duplicate frequencies so use st.find().
				st.erase(st.find(mpp[s[j]]));
			}

			mpp[s[j]]++;
			st.insert(mpp[s[j]]);

			res += (*st.rbegin() - *st.begin());
		}
	}

	return res;

	// TC --> O(n^2 * logn)
	// Reason -> each insertion in set takes O(logn) time and there are total n^2 insertions.
	// SC --> O(n+n)
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

	cout << beautySum1(s) << endl;

}