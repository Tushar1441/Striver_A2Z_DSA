#include <bits/stdc++.h>
using namespace std;

void sumOf_firstN(int i, int sum) {
	if (i < 0) {
		cout << sum << endl;
		return;
	}

	sumOf_firstN(i - 1, sum + i);
}

int sum_functional(int n) {
	if (n < 0)return 0;

	return n + sum_functional(n - 1);
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n;
	cin >> n;
	cout << sum_functional(n) << endl;;
}