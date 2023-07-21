#include <bits/stdc++.h>
using namespace std;

// Because it is already given that the string is a valid parentheses string,
// then we only need to check the max number of continous '('.
int maxDepth(string s) {
	int maxi = 0, curr = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') curr++;
		else if (s[i] == ')') {
			curr--;
		}

		maxi = max(maxi, curr);
	}

	return maxi;

	// TC --> O(n)
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

	cout << maxDepth1(s) << endl;

}

