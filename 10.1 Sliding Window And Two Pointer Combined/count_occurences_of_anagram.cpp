#include <bits/stdc++.h>
using namespace std;

int countAnagrams(string& text, string &pat) {
	int n = text.size();
	int m = pat.size();

	// store the pattern characters frequency
	vector<int>hashpat(26, 0);
	for (int i = 0; i < m; i++) {
		hashpat[pat[i] - 'a']++;
	}

	// storing frequency of characters in string : txt
	vector<int>hashTxt(26, 0);
	int ans = 0;
	int right = 0, left = 0;

	while (right < n) {

		// update the text character freq
		hashTxt[text[right] - 'a']++;

		if (right - left == m - 1) {
			// if substring is matched then increase the count
			if (hashTxt == hashpat)ans++;

			hashTxt[text[left] - 'a']--;
			left++;
		}

		right++;
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
	string a, b;
	cin >> a >> b;
	cout << countAnagrams(a, b) << endl;
}