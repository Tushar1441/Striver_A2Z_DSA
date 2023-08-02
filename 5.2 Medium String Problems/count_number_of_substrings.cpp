#include <bits/stdc++.h>
using namespace std;


int countSubStrings(string s, int k) {
	int res = 0;
	int n = s.size();

	for (int i = 0; i <= n - k; i++) {
		unordered_set<char>st;
		int curr = 0;
		for (int j = i; j < n; j++) {

			if (st.find(s[j]) == st.end()) {
				st.insert(s[j]);
				curr++;
			}


			if (curr == k) {
				res++;
			}

			if (curr > k)break;
		}

	}


	return res;

	// TC--> O(n^2)
	// SC --> O(26) --> Max length of set.
}


// the number of subarrays with at most K distinct elements
// using acquire and release strategy
// aquire till unique characters in the window crosses k
// and then release until the unique characters in the window becomes k.
int most_k_chars(string s, int k) {
	int n = s.length();

	int left = 0, right = 0;
	int res = 0;

	unordered_map<char, int>mpp;

	while (right < n) {
		mpp[s[right]]++;
		if (mpp.size() > k) {
			while (mpp.size() > k) {
				mpp[s[left]]--;
				if (mpp[s[left]] == 0)mpp.erase(s[left]);
				left++;
			}
		}

		// add the window
		res += right - left + 1;
		right++;
	}

	return res;
}

int countSubStrings1(string s, int k) {
	// it is easy to find substring with atmost k characters
	// so intead of directly finding, we will do
	// number of substring with atmost k chars - number of substring with atmost k-1 chars
	return most_k_chars(s, k) - most_k_chars(s, k - 1);
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int k;
	string s;
	cin >> s >> k;

	cout << countSubStrings1(s, k) << endl;

}

