#include <bits/stdc++.h>
using namespace std;


string removeParantheses(string &s) {
	string ans = "";
	int bal  = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			if (bal) {
				ans.push_back('(');
			}
			bal += 1;
		}

		else {
			bal -= 1;
			if (bal)ans.push_back(')');
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
	cout << removeParantheses(s) << endl;

}

