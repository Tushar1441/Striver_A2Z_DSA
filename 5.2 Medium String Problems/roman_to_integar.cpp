#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
	int arr[26] = {0};

	arr['I' - 'A'] = 1;
	arr['V' - 'A'] = 5;
	arr['X' - 'A'] = 10;
	arr['L' - 'A'] = 50;
	arr['C' - 'A'] = 100;
	arr['D' - 'A'] = 500;
	arr['M' - 'A'] = 1000;

	int ans = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (i == s.size() - 1)ans += arr[s[i] - 'A'];

		else {
			if (arr[s[i] - 'A'] < arr[s[i + 1] - 'A']) ans -= arr[s[i] - 'A'];
			else ans += arr[s[i] - 'A'];
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

	cout << romanToInt(s) << endl;

}

