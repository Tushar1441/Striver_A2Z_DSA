#include <bits/stdc++.h>
using namespace std;


int GCD(int n, int m) {
	int a = max(n, m);
	int b = min(n, m);

	while (b > 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}

	return a;
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

	cout << GCD(n, m) << endl;


}