#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach
// Just do linear search for every digit from 0->n in the array and output the missing number

int findMissingNumber1(vector<int> &arr, int n) {
	// Outer loop that runs from 0 to N-1:
	for (int i = 0; i < n; i++) {

		// flag variable to check
		//if an element exists
		int flag = 0;

		//Search the element using linear search:
		for (int j = 0; j < n ; j++) {
			if (arr[j] == i) {

				// i is present in the array:
				flag = 1;
				break;
			}
		}

		// check if the element is missing
		//i.e flag == 0:

		if (flag == 0) return i;
	}

	// if no element if found missing before then it will be (n)(because we are running our loop
	//	for only (0 --> n-1) ).
	return n;

	// TC --> O(n*2)
	// SC --> O(1)
}



// Better Approach
// Using hash table

int findMissingNumber2(vector<int> &arr, int n) {
	// initialise a hash table
	int hash[n + 1] = {0};

	// iterate through the array ad update the frequencies
	for (int i = 0; i < n; i++) {
		hash[arr[i]]++;
	}

	// Output the digit with 0 frequency in the hash array
	for (int i = 0; i <= n; i++) {
		if (hash[i] == 0) {
			return i;
		}
	}

	return -1;

	// TC --> O(n) + O(n)  (running two loops for n times)
	// SC --> O(n) (due to hash array)

}



// Optimal approach 1 -- Using summition

int findMissingNumber3(vector<int> &arr, int n) {
	// initialise a sum variable and store the sum of all the array elements into it
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	// the sum of first  n natural numbers is always --> n*(n+1)/2
	// so, the missing number will be (sum_natural - sum)

	return (n * ((n + 1) / 2) - sum);

	// TC --> O(n) (running a loop for calculating the sum)
	// SC --> O(1)
}



// Optimal Approach 2--> Using XOR function
int findMissingNumber(vector<int> &arr, int n) {
	// intialise two variables
	// one contains the xor of all the digits from 0 to n
	// second contains the xor of all the elements present in the array
	int xor1 = n; // initialise with n because the loop only goes from (0 -> n-1)
	int xor2 = 0;

	for (int i = 0; i < n; i++) {
		xor1 ^= i;
		xor2 ^= arr[i];
	}

	return xor1 ^ xor2;

	// TC --> O(n) (running a loop to calculate both the xor values)
	// SC --> O(1) (storing only two variables)
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, temp;
	cin >> n ;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;
	}

	int ans = findMissingNumber(arr, n);
	cout << ans << endl;
	// for (int i = 0; i < arr.size(); i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;
}