#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, k, h;
	cin >> n >> m >> k >> h;

	int res = 0;

	int curr;
	for (int i = 0; i < n; i++) {
		cin >> curr;
		int diff = abs(curr - h);
		if (diff % k == 0 && diff <= (m - 1)*k && diff != 0 ) {
			res++;
		}

	}
	cout << res << endl;
	return;
}

void solve1() {
	int n;
	cin >> n;

	vector<int>arr, arr1;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
		arr1.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		if ((arr[i] & 1) != (arr1[i] & 1)) {
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;
	return;
}

void solve2() {
	long long n, k;
	cin >> n >> k;

	long long arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long long last = n - 1, firstcnt = 0, lastcnt = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[0])firstcnt++;
		if (firstcnt == k) {
			last = i;
			break;
		}
	}

	if (firstcnt >= k && arr[0] == arr[n - 1]) {
		cout << "YES" << endl;
		return;
	}

	for (int i = n - 1; i > last; i--) {
		if (arr[i] == arr[n - 1])lastcnt++;
	}

	if (lastcnt >= k) cout << "YES" << endl;
	else cout << "NO" << endl;

	return;
}


void solve3() {
	long long n, temp;
	cin >> n;

	vector<long long> arr;
	set<long long> st;
	st.insert(n);

	for (int i = 0; i < n - 1; i++) {
		cin >> temp;
		arr.push_back(temp);
		st.insert(i + 1);
	}


	bool flag = 1;
	long long left = -1;

	if (arr[0] <= n && arr[0] >= 1) {
		st.erase((arr[0]));
	}
	else {
		left = arr[0];
	}

	for (int i = 1; i < n - 1; i++) {
		int diff = arr[i] - arr[i - 1];
		if (st.find(diff) != st.end()) {
			st.erase(diff);
		}
		else if (left == -1) left = diff;
		else {
			flag = 0;
			break;
		}
	}

	if (flag == 0)  cout << "NO" << endl;

	else {
		long long res = 0;
		for (auto it : st) res += it;

		if (left != -1) {
			if (res == left) cout << "YES" << endl;
			else cout << "NO" << endl;
		}

		else {
			long long req = n * (n + 1) / 2;
			if (res == req - arr[n - 2]) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}

	return;
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
		solve2();
	}
}