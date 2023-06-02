#include <bits/stdc++.h>
using namespace std;

bool ArmstrongNumber(int n) {
	int num = 0;
	int temp = n;
	while (n > 0) {
		num += (n % 10) * (n % 10) * (n % 10);
		n /= 10;
	}

	if (num == temp) return true;
	return false;
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
	cout << ArmstrongNumber(n) << endl;
}
