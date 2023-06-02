#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
	if (n <= 1)return n;

	return fib(n - 1) + fib(n - 2);
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
	cout << fib(n);

}