#include <bits/stdc++.h>
using namespace std;

int reverseInteger(int N) {
	int x = N;
	int newnum  = 0;
	while (x != 0) {

		// while doing newnum*10 , there can be a possibility that the number
		// reach outside its int range ,
		//  so we have to put a check before doing the multiplication

		if ((newnum > INT_MAX / 10) || (newnum < INT_MIN / 10) ) return 0;
		newnum = newnum * 10 + (x % 10);
		x /= 10;

	}
	return newnum;
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
	cout << reverseInteger(n) << endl;
}
