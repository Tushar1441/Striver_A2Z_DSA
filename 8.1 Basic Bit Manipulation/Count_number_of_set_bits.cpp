#include <bits/stdc++.h>
using namespace std;


int countSetBits1(int n) {
	int count = 0;
	while (n) {
		if (n & 1) {
			count++;
		} ;
		n >>= 1;
	}

	return count;
	// TC --> O(logn) beacuse there are logn number of bits in a number n.
	// SC --> O(1);
}

// Method-2 --> Unset the rightmost set bit and count the iteration until the num becomes 0.
int countSetBits2(int n) {

	// Initialising a variable to count the total.
	int total = 0;

	while (n) {

		// Taking AND of N with N - 1 --> Unset the rightmost bit.
		n = n & (n - 1);

		// Increment total on each iteration.
		++total;

	}
	return total;

	// TC --> O(number of set bits) , in worst case all bits are set.
	// TC --> O(logn)
	// SC --> O(1)
}

// Method 3-->
int countSetBits3(int n) {
	int total = 0;
	for (int i = 0; i < 32; i++) {
		// check if ith bit of the number is set.
		if (n & (1 << i)) {
			++total;
		}
	}

	return total;

	// TC --> O(1) --> running loop for constant duration
	// SC --> O(1)
}


// Method -4 --> Using stl fuction
int countSetBits(int n) {
	return __builtin_popcount(n);
	// TC --> O(total set bits in the number)
	// TC --> O(logn)
	// SC --> O(1)
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, i;
	cin >> n;
	cout << countSetBits(n) << endl;

}