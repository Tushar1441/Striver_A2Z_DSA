#include <bits/stdc++.h>
using namespace std;

void print_1toN( int n) {
	if (n == 0) return;
	print_1toN(n - 1);
	cout << n << " ";
}

void print_Nto1(int n) {
	if (n == 0)return;
	cout << n << " ";
	print_Nto1(n - 1);
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
	print_1toN(n);
	cout << endl;
	print_Nto1(n);
}