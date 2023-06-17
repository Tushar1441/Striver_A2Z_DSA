#include <bits/stdc++.h>
using namespace std;


// Method 1 --> compare the first string with all the strings.
string longestCommonPrefix1(vector<string> &arr) {
	string ans = "";
	char ch;
	for (int i = 0; i < arr[0].length(); i++) {
		ch = arr[0][i];

		for (int j = 1; j < arr.size(); j++) {
			if (ch != arr[j][i]) return ans;
		}
		ans += ch;
	}

	return ans;

	// TC --> O(n * str) str is the length of first string.
	// SC --> O(1).
}


// Method 2 --> sort the string and compare the first and last strings.
// Intiution --> the least common prefix for any two strings in the array
// will be for the first and last string.
string longestCommonPrefix(vector<string> &arr) {
	sort(arr.begin(), arr.end());
	string ans = "";
	string end = arr.back();

	for (int i = 0; i < arr[0].size(); i++) {
		if (arr[0][i] == end[i])ans += end[i];
	}

	return ans;

	// TC --> O(n * logn) + O(str) str is the length of first/smallest string.
	// SC --> O(1).
}

int directedSoldiers(int n, vector<int> &a) {
	int ans = 0;
	int i = n - 1;
	int cnt0 = 0, cnt1 = 0;

	while (i >= 0) {
		if (a[i] == 0) {
			cnt0++;
// 0, 1, 1, 0, 1, 0, 0
		}
		else {
			cnt1++;
			cout << cnt0 << " " << cnt1 << endl;
			if (i == 0  ||  (i != 0 && a[i - 1] == 0)) {
				// cout << "hello" << endl;
				ans = min(cnt0, cnt1);
				cout << ans << endl;
				// cnt0 = 0;
				// cnt1 = 0;
			}
		}

		i--;
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
	// string temp;
	// int n;
	// cin >> n;
	// vector<string> arr;
	// for (int i = 0; i < n; i++) {
	// 	cin >> temp;
	// 	arr.push_back(temp);
	// }

	// string ans = longestCommonPrefix(arr);
	// cout << ans << endl;
	int n = 7;
	vector<int>arr = {0, 1, 1, 0, 1, 0, 0};
	cout << directedSoldiers(n, arr) << endl;

}

