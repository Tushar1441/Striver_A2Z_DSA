#include <bits/stdc++.h>
using namespace std;


bool powerOf2(int n) {
	return ((n & (n - 1))  == 0 ) ? 1 : 0;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, i;
	cin >> n;
	cout << powerOf2(n) << endl;


}