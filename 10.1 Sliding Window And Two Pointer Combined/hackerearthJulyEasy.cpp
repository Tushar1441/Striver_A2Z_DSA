#include <bits/stdc++.h>
using namespace std;

// int GCD(int n, int m) {
// 	int a = max(n, m);
// 	int b = min(n, m);

// 	while (b > 0) {
// 		int temp = b;
// 		b = a % b;
// 		a = temp;
// 	}

// 	return a;
// }

// void solve3() {
// 	int n, temp;
// 	cin >> n;
// 	vector<int>arr;
// 	for (int i = 0; i < n; i++) {
// 		cin >> temp;
// 		arr.push_back(temp);
// 	}

// 	int max_element =  -1;
// 	for (int i = 0; i < n; i++) if (arr[i] > max_element) max_element = arr[i];
// 	int max_prefix_gcd = 0;

// 	for (int i = max_element; i > 0; --i) {
// 		int current_gcd = 0;
// 		for (int j = 0; j < n; ++j) {
// 			if (arr[j] % i == 0) {
// 				current_gcd = GCD(current_gcd, arr[j]);
// 			}
// 		}
// 		max_prefix_gcd += current_gcd;
// 	}

// 	cout << max_prefix_gcd << endl;
// }

// void solve4() {
// 	int n;
// 	cin >> n;
// 	set<int>ans;

// 	for (int i = 2; i * i <= n; i++) {
// 		while (n % i == 0) {
// 			ans.insert(i);
// 			n = n / i;
// 		}
// 	}

// 	if (n > 1)ans.insert(n);
// }

void solve5() {
	int n, k, temp;
	cin >> n >> k;

	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());
	int groups = 0;

	for (int i = 0; i < n; i++) {

		int max_groups = arr[i] / (k / 2);

		groups += max_groups;

		// occurrences -= max_groups * (k / 2);
	}

	cout << groups << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int t;
	cin >> t;
	while (t--) {
		solve5();
	}
}