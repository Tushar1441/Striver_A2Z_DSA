#include <bits/stdc++.h>
using namespace std;



countDigits(int n) {
	if (n % 2 != 0)return 0;

	int x = n;
	int count = 0;


	while (x > 0) {
		if (x % 10 == 0) {
			x /= 10;
			continue;
		}

		if ((n % (x % 10))  == 0)count++;
		x /= 10;
	}

	return count;
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

	cout << countDigits(n) << endl;


}
