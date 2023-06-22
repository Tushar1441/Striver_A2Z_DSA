#include <bits/stdc++.h>
using namespace std;


// Brute force approach --> Generate all the subarrays using three nested for loops
int longestSubarray1(vector<int>& arr, int n, int k) {

	int count = 0;
	for (int i = 0; i < n; i++) { // starting index
		for (int j = i; j < n; j++) { // ending index
			// add all the elements of
			// subarray = a[i...j]:
			long long s = 0;
			for (int K = i; K <= j; K++) {
				s += arr[K];
			}

			if (s == k)
				count++;
		}
	}

	return count;

	// TC --> O(n*3) (running three nested loops)
	// SC --> O(1)
}


// Brute Force approach (Best case)--> Using two nested for loops
int longestSubarray2(vector<int> &arr, int n, int k) {

	int count = 0;

	for (int i = 0; i < n; i++) { // starting index
		// initialise a sum var
		long long sum = 0;

		// running another loop to iterate over the next elements until the required sum is not obtained
		for (int j = i; j < n; j++) {

			// if at any time , the sum exceeds k , break the loop.
			if (sum > k)break;
			sum += arr[j];

			// check for the maxlength
			if (sum == k) count++;

		}
	}

	return count;

	// TC --> O(N*2) (running two nested loops both for max n times )
	// SC --> O(1) (no extra space required)
}




// Bettter Approach --> Using Hashmap
// this approach becomes optimal if arr contains negative elements
int longestSubarray3(vector<int> & arr, long long k) {
	int n = arr.size();
	long long sum = 0;
	int maxlength = 0;
	map<long long, int> prefixSum;

	for (int i = 0; i < n; i++) {

		//calculate the prefix sum till index i:
		sum += arr[i];

		long long rem = sum - k;

		if (prefixSum.find(rem) != prefixSum.end())count += prefixSum[rem];

		prefixSum[sum] += 1;

	}

	return count;
	// TC --> O(N) or O(N*logN)
	// for unrodered set O(1) in best and average case ans O(n^2) in worst case
	// or using ordered set -> logn
	// SC --> O(n) as we are using a hash map data structure
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, temp;
	long long k;
	cin >> n >> k ;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;
	}

	int ans = longestSubarray(arr, k);
	cout << ans << endl;

}