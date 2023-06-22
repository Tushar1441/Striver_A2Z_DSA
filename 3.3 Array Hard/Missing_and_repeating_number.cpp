#include <bits/stdc++.h>
using namespace std;


// Brute force approach
// Do linear Search for every element in the array.
// if(count of i+1 is 0)then i is missing number
// if(count of i+1 is 2)then i is repeating number
// TC --> O(n^2);
// SC --> O(1)

// Better Approach -> Using Hashmap
pair<int, int> findNumbers1(vector<int> arr) {
	int n = arr.size();
	unordered_map<int, int>hashmap;


	// store the frequencies.
	for (int i = 0; i < n; i++) {
		hashmap[arr[i]]++;
	}

	// initialise both the answers
	int first = -1;
	int second = -1;

	// check the elements
	for (int i = 1; i <= n; i++) {
		if (hashmap[i] == 0) first = i;
		if (hashmap[i] == 2) second = i;
	}

	return {first, second};

	//TC --> O(n + n) or O(n + n*logn)
	//SC --> O(n)
}



// Optimised Approach --> Using Summition Observation
// S = Sum of all the array elements
// S2 = sum of squares of all arr elements
// Sn = Sum of first n natural numbers
// S2n = Sum of squares of first n natural numbers
pair<int, int> findNumbers2(vector<int> arr) {

	long long n = arr.size();
	long long Sn = n * (n + 1) / 2;
	long long S2n = n * (n + 1) * (2 * n + 1) / 6;

	long long S = 0, S2 = 0;

	for (int i = 0; i < n; i++) {
		S += arr[i];
		S2 += (long long)arr[i] * (long long)arr[i];
	}

	// missing and repeating number
	int x = -1, y = -1;

	// S-Sn == x - y
	long long diff = S - Sn;

	// S2 - S2n == x^2 - y^2
	long long diff2 = S2 - S2n;


	// x+y == (x^2 - y^2)/x - y;
	long long sum = diff2 / diff;

	// x = (x+y)- (x-y) / 2;
	x = (sum - diff) / 2;
	y = (sum - x);


	return {x, y};

	//TC --> O(n)
	//SC --> O(1)
}



// Optimized Approach --> Using Xor
pair<int, int> findNumbers(vector<int> arr) {
	int n = arr.size();
	int xr = 0;

	// xor all the elements and indexes
	for (int i = 0; i < n; i++) {
		xr ^= arr[i];
		xr ^= i + 1;
		// now the xor contains --> x^y
	}


	//find the differentiating bit of the two numbers
	// or we can say, just find the least significant set bit of xor
	int  bitno = 0;
	while (1) {
		if (xr & (1 << bitno))break;
		bitno++;
	}

	//Step 3: Group the numbers:
	int zero = 0;
	int one = 0;

	for (int i = 0; i < n; i++) {
		//part of 1 group:
		if ((arr[i] & (1 << bitno))) {
			one = one ^ arr[i];
		}

		//part of 0 group:
		else {
			zero = zero ^ arr[i];
		}


		// including the 1 based indexes in the xor values.
		if ( (i + 1) & (1 << bitno)) {
			one = one ^ (i + 1);
		}
		else {
			zero = zero ^ (i + 1);
		}
	}


	// Last step: Identify the numbers:
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == zero) cnt++;
	}

	if (cnt == 2) return {zero, one};
	return {one, zero};

	// TC --> O(n + n + n)
	// SC --> O(1)

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, temp;
	cin >> n;;

	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	pair<int, int> ans = findNumbers(arr);
	cout << ans.first << " " << ans.second << endl;

}