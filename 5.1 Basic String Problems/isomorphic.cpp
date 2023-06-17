#include <bits/stdc++.h>
using namespace std;


bool isIsomorphic(string &s, string &t) {
	vector<int>hashh1[200];
	vector<int>hashh2[200];

	for (int i = 0; i < s.size(); i++) {
		hashh1[s[i]]++;
	}
	for (int i = 0; i < t.size(); i++) {
		hashh2[t[i]]++;
	}

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

