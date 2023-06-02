#include <bits/stdc++.h>
using namespace std;

bool printDivisors(int n) {

	// Method 1 --> Iterate over all the numbers from 0 to n and find out the divisors by dividing them with the number
	// for (int i = 1; i <= n; i++) {
	// 	if (n % i == 0)cout << i << " ";
	// }
	// cout << endl;

	// Method 2 --> Iterate over only Sqrt(n) numbers
	// n=36 --> for sqrt(36) = 6 , divisors == 1*36 , 2*18 , 3*12 , 4*9 ,6*6

	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			cout << i << " ";
			if (i != n / i )cout << n / i << " ";
		}
	}
	cout << endl;
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
	printDivisors(n);
}
