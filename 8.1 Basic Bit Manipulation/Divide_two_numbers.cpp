#include <bits/stdc++.h>
using namespace std;



// Brute Force Approach --> Subtracting the divisor from divident iteratively
int divideNumbers1(int a, int b) {
	int ans = 0;

	int neg = -1 ;
	if ((a >= 0 && b >= 0) || (a < 0 && b < 0))neg = 1;

	if (b == 1)return a;
	if (a == INT_MIN)a++;

	a = abs(a); b = abs(b);

	while (a >= b) {
		a -= b;
		ans++;
	}

	return ans * neg;

	// TC --> O(a/b);
	// SC --> O(1);
}

int divideNumbers(int a, int b) {
	if (b == 1)return a;
	if (a == INT_MIN) {
		if (b == 1)return INT_MIN;
		else if (b == -1)return INT_MAX;
	}

	int neg = -1;
	if ((a >= 0 && b >= 0) ||  (a < 0 && b < 0))neg = 1;
	int ans = 0;

	a = abs(a); b = abs(b);

	int low = 0; int high = a;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (mid * b <= a) {
			ans = mid;
			low = mid + 1;
		}

		else {
			high = mid - 1;
		}
	}

	return ans * neg;

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
	cout << divideNumbers(n, m) << endl;
}