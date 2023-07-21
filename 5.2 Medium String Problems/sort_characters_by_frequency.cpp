#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, char>&a, pair<int, char>&b) {
	return a.first >= b.first;
}

string frequencySort(string s) {

	// total chars = 256.
	vector<pair<int, char>>mpp(256);

	// store the frequency and char in the hash pair array.
	for (int i = 0; i < s.size(); i++) {
		mpp[s[i]].first++;
		mpp[s[i]].second = s[i];
	}

	// either we sort the frequency in decreasing order
	// or we can later reverse the answer string.
	sort(mpp.begin(), mpp.end(), comp);

	string ans = "";

	for (auto &it : mpp) {
		for (int i = 0; i < it.first; i++) {
			ans += it.second;
		}
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
	string s;
	cin >> s;

	cout << frequencySort(s) << endl;

}

