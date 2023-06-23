#include <bits/stdc++.h>
using namespace std;

// Brute Force --> Just do a linear search on the array and find the two elements
// appearing once in the whole array using two nested for loops.
// TC --> O(n^2)



// Optimal Approach --> Using Bitwise Xor
vector<long long int> twoOddOccurences(vector<long long int>& arr)
{
	int n = arr.size();

	// Take the xor of all the array elements
	int xor1 = 0;
	for (int i = 0; i < n; i++) {
		xor1 ^= arr[i];
		// it contains a^b
	}

	// find the smallest differentiating bit position.
	// or just find the rightmost set bit.
	int setBit = 0;

	while (1) {
		if (xor1 & (1 << setBit)) {
			break;
		}
		setBit++;
	}

	// This set bit position signifies that both the numbers are
	// are different at this particular bit.


	vector<long long int> nums;

	// group all the numbers into two groups having the bitno position
	// bit as 1 or 0.
	int xor2 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] & (1 << setBit)) {
			xor2 ^= arr[i];
		}
	}

	nums.push_back(xor2);
	nums.push_back(xor1 ^ xor2);

	return nums;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	long long int n, temp;
	cin >> n ;
	vector<long long int> arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	twoOddOccurences(arr);
}