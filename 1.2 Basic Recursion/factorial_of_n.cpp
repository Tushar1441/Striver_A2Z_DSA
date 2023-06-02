#include <bits/stdc++.h>
using namespace std;

void factorial(int fact, int n) {
	if (n <= 1) {
		cout << fact << endl;
		return;
	}
	fact *= n;
	factorial(fact, n - 1);
}

int factorial_functional(int n) {
	if (n < 1)return 1;

	return n * factorial_functional(n - 1);
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
	cout << factorial_functional( n) << endl;;
}