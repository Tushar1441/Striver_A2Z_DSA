#include <bits/stdc++.h>
using namespace std;


vector<int> allPrimeNumbers(int n) {
	vector<int>ans;

	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ans.push_back(i);
			n = n / i;
		}
	}

	if (n > 1)ans.push_back(n);
	return ans;
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
	allPrimeNumbers(n);

}