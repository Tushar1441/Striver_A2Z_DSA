#include <bits/stdc++.h>
using namespace std;

// Helper function to check if a string is palindrome or not.
bool isPalindrome(string s, int start, int end) {
	while (start <= end) {
		if (s[start++] != s[end--])return false;
	}

	return true;
	// TC --> O(n/2)
}


// Optimal Solution --> Using Backtracking
// We will start from the ith idx every time and look for all the ways we can
// partition the remaining string.
// We only care about the first half.
// The second half will be take cared by recursion.
void solve(int idx, vector<string> &ds, vector<vector<string>>&ans, string s) {
	// if string is exhausted,add the partitioned 1D arr to the ans 2D array.
	if (idx == s.size()) {
		ans.push_back(ds);
		return;
	}

	// look for partitions in the remaining string (i.e. from idx to n)
	for (int i = idx; i < s.size(); ++i) {
		// check if the first half is a palindrome(i.e idx to i)
		// if yes then include it in our partitioned array and call the recursion for the second half.
		if (isPalindrome(s, idx, i)) {
			ds.push_back(s.substr(idx, i - idx + 1));
			solve(i + 1, ds, ans, s);
			ds.pop_back();
		}
	}

	// at last the ans 2D array will be returned with all the answers.
	// Time Complexity: O( (2^n) *k*(n/2) )

	// Reason: O(2^n) to generate every substring and O(n/2)  to check
	// if the substring generated is a palindrome.
	// O(k) is for inserting the palindromes in another data structure,
	// where k  is the average length of the palindrome list.


	// Space Complexity: O(k * x) + O(n) --> answer array space + recursion stack space
	// Reason: The space complexity can vary depending upon the length of the answer.
	// k is the average length of the list of palindromes
	// and if we have x such list of palindromes in our final answer.

}


vector<vector<string>> partition(string s) {
	vector<string> ds;
	vector<vector<string>>ans;
	string bal = "";
	solve(0, ds, ans, s);
	return ans;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	string n;
	cin >> n ;

	vector<vector<string>>ans = partition(n);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}


