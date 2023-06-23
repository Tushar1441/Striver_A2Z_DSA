#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
vector<bool>isPrime(N, 1);


void sieve() {
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i <= N; i++) {
		if (isPrime[i] == true) {
			for (int j = i * i; j <= N; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

int countPrime(int n, vector<bool>&isPrime) {
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (isPrime[i] == true)count++;
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

	// call the sieve function
	sieve();
	cout << countPrime(n, isPrime) << endl;

}