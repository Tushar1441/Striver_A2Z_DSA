#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
	string word = "";
	string ans = "";

	for (int i = 0; i < s.size(); i++) {

		// if ' ' is found then it means we have a complete word.
		// To insert the word in our answer string there two options -
		// i) if ans is empty then we do not need leading space
		// ii) else we need a leading space before a word

		if ( s[i] == ' ') {
			if (ans.empty())ans = word;
			else if (!word.empty()) {
				ans = word + " " + ans;
			}
			word = "";
		}

		else if (s[i] != ' ') {
			word += s[i];
		}

	}

	// add the last word to the answer string in the same manner.
	if (!word.empty()) {
		if (ans.empty())ans = word;
		else ans = word + " " + ans;
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

	cout << reverseWords(s) << endl;

}