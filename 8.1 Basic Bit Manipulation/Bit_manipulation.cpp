#include <bits/stdc++.h>
using namespace std;


bool getBit(int n, int i) {
	return (n |= ~(1 << i - 1));
}

int setBit(int n, int i) {
	return (n |= ( 1 << i - 1 ));
}

int clearBit(int n, int i) {
	return (n &= ~(1 << i - 1) );
}

bool isIthSet(int n, int i) {
	return (n &= (1 << i - 1));
}

bool isOdd(int n) {
	return (n & 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, i;
	cin >> n >> i;
	cout << getBit(n, i) << endl;
	cout << setBit(n, i) << endl;
	cout << clearBit(n, i) << endl;
	cout << isIthSet(n, i) << endl;
	cout << isOdd(n) << endl;

}