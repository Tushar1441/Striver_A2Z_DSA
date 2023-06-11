#include <bits/stdc++.h>
using namespace std;


void swapTwoNumbers(int &a, int &b) {
	int x = a ^ b;
	a ^= x;
	b ^= x;

	return;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, m;
	cin >> n >> m;
	swapTwoNumbers(n, m) ;
	cout << n << " " << m << endl;
}