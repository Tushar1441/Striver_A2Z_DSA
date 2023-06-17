#include <bits/stdc++.h>
using namespace std;


string reverse1(string &s) {
	// store all the words in a stack.
	stack<string>st;
	s += ' ';
	string word = "";
	for (int i = 0; i < s.length(); i++) {
		// a word ends with a blank space ' '.
		if (s[i] == ' ') {
			st.push(word);
			word = "";
		}
		else word += (s[i]);
	}

	// put the stack elements into an answer string.
	string ans = "";
	while (st.size() != 1) {
		ans += st.top();
		ans += ' ';
		st.pop();
	}
	ans += st.top();

	return ans;
	// TC --> O(n);
	// SC --> O(n);
}



// Optimal Solution --> without using stack;
string reverse2(string &s) {
	string word = "";
	string ans = "";

	for (int i = 0; i < s.size(); i++) {
		char ch = s[i];

		if (ch != ' ') {
			word += ch;
		}
		else if ( ch == ' ' ) {
			if (ans.empty())ans = word;
			else {
				ans = word + " " + ans;
			}
			word = "";
		}


	}

	if (word != "") {
		if (!ans.empty()) ans = word + " " + ans;
		else ans = word;
	}
	return ans;
}

// Solution 3 --> reverse the entire string and then reverse each word.
string reverse3(string s) {
	// Reverse the entire string
	reverse(s.begin(), s.end());

	// Initialize loop variables
	int L = 0, r = 0, i = 0, n = s.size();
	while (i < n) {
		// Find the end of the current word
		while (i < n && s[i] != ' ') {
			s[r] = s[i];
			r++; i++;
		}

		// Reverse the current word and advance loop pointers
		if (L < r) { // If there was a non-empty word
			reverse(s.begin() + L, s.begin() + r); // Reverse the word
			if (r == n) break; // If this was the last word, break
			s[r++] = ' '; // Add a space after the word
			L = r; // Move L to the next character after the space
		}

		// Move to the next character in the input string
		++i;
	}

	// Remove trailing whitespace (if any)
	if (r > 0 && s[r - 1] == ' ') --r;
	s.resize(r);

	// Return the final reversed string with reversed words
	return s;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	string s = " hello world ";
	reverse(s);
	cout << s << endl;

}

