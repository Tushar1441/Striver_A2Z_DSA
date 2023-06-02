#include <bits/stdc++.h>
using namespace std;

void print_1toN(int cnt, int n) {
	if (cnt > n) return;
	cout << cnt << " ";
	cnt++;
	print_1toN(cnt , n);
}

void print_Nto1(int cnt , int n) {
	if (cnt > n)return;
	cout << n - cnt + 1 << " ";
	cnt++;
	print_Nto1(cnt, n);
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
	print_Nto1(1, n);
}