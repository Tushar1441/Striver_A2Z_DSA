#include <bits/stdc++.h>
using namespace std;


void solve() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a + b > 9 || b + c > 9 || a + c > 9)cout << "YES" << endl;
	else cout << "NO" << endl;
}

void solve1() {
	int n;
	cin >> n;
	int ans = INT_MIN,  idx = 0, res = 0;
	while (idx < n) {
		int a, b;
		cin >> a >> b;

		if (a <= 10 && ans < b) {
			ans = b;
			res = idx + 1;
		}

		idx++;
	}

	cout << res << endl;
}

void solve2() {

	string ans = "";

	int n = 8;
	while (n--) {
		string str;
		cin >> str;
		for (char it : str) {
			if (it <= 'z' && it >= 'a') {
				ans += it;
				break;
			}
		}
	}

	cout << ans << endl;
}

bool is_balanced(vector<int>& arr, int n, int k, int mid) {
	int window_start = 0;
	for (int i = mid; i < n; i++) {
		if (arr[i] - arr[window_start] > k) {
			return false;
		}
		++window_start;
	}
	return true;
}


void solve3() {
	int n , k;
	cin >> n >> k;

	vector<int>arr;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin() , arr.end());

	int i = 0, res = 0;

	while (i < n)
	{
		int j = i + 1;

		while (j < n  && arr[j] - arr[j - 1] <= k) j++;

		int curr = j - i;
		res = max(res , curr);
		i = j;
	}

	cout << n - res << endl;
}

void solve4() {
	long long n, c, sideSum = 0;
	cin >> n >> c;

	vector<int>arr;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		arr.push_back(a);
		sideSum += a;
		c -= a * a;
	}

	c /= 4;
	c /= n;

	sideSum /= 2 * n;

	int res = sqrtl(sideSum * sideSum +  c);
	res -= sideSum;
	cout << res << endl;

}

void solve5() {
	int  n, x;
	cin >> n;

	vector<int> v(n + 1, 0);
	long long mpp[n + 1] = {0};

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x <= n)	mpp[x]++;

	}


	for (int i = 1; i <= n; i++)
	{
		if (mpp[i] != 0) {
			for (int j = i; j <= n; j += i)
			{
				v[j] += mpp[i];
			}
		}
	}

	int maxi = INT_MIN;
	for (auto &it : v) {
		if (it > maxi)maxi = it;
	}

	cout << maxi << endl;
}


void solve6() {
	int n;
	cin >> n;
	vector<pair<int, int>>arr;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({a, b});
	}

	long long res = 0;
	long long curr = 0;
	int last = 0;
	for (int i = 1; i < n ; i++) {
		if (arr[i].first - arr[last].first == 0
		        || arr[last].first - arr[i].first == 0
		        || arr[i].second - arr[last].second == 0
		        || arr[last].second - arr[i].second == 0
		        || arr[i].first - arr[last].first == arr[i].second - arr[last].second
		        || arr[last].first - arr[i].first == arr[i].second - arr[last].second
		        || arr[last].first - arr[i].first == arr[last].second - arr[i].second
		        || arr[i].first - arr[last].first == arr[last].second - arr[i].second
		   ) {
			curr++;
			last = i;
		}

		res += curr * 2;

	}

	cout << res << endl;
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