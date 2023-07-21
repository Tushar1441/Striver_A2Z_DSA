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


int countSubStrings1(string s, int k) {
	int n = s.size();

	unordered_set<char>st;
	int left = 0, right = 0, res = 0;

	while (right < n) {
		st.insert(s[right]);

		if (st.size() == k)res++;

		while (st.size() > k) {

		}
	}
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

	cout << countSubStrings(s, k) << endl;

}

