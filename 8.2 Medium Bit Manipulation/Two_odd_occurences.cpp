#include <bits/stdc++.h>
using namespace std;

// Brute Force --> Just do a linear search on the array and find the two elements
// appearing once in the whole array.
// TC --> O(n*n) --> n for selecting elements from the array and n for iterating for all the elements


vector<long long int> twoOddOccurences(vector<long long int>& arr)
{
	int n = arr.size();
	int xor1 = 0;
	for (int i = 0; i < n; i++) {
		xor1 ^= arr[i];
	}
	int setBit = 0;
	int x = xor1;
	while (x) {
		if (x & 1) {
			break;
		}
		setBit++;
		x >>= 1;
	}

	vector<long long int> nums;

	int xor2 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] & (1 << setBit)) {
			xor2 ^= arr[i];
		}
	}

	nums.push_back(xor2);
	nums.push_back(xor1 ^ xor2);

	for (auto it : nums) {
		cout << it << " ";
	}

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