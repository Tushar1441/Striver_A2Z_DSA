#include <bits/stdc++.h>
using namespace std;



// Brute force approach --> Generate all the subarrays using three nested for loops

int longestSubarray1(vector<int>& arr, int n, int k) {

	int maxlength = 0;
	for (int i = 0; i < n; i++) { // starting index
		for (int j = i; j < n; j++) { // ending index
			// add all the elements of
			// subarray = a[i...j]:
			long long s = 0;
			for (int K = i; K <= j; K++) {
				s += arr[K];
			}

			if (s == k)
				maxlength = max(maxlength, j - i + 1);
		}
	}
	return maxlength;

	// TC --> O(n*3) (running three nested loops)
	// SC --> O(1)
}

// Brute Force approach (Best case)--> Using two nested for loops
int longestSubarray2(vector<int> &arr, int n, int k) {

	int maxsubarr = 0;

	for (int i = 0; i < n; i++) { // starting index
		// initialise a sum var
		long long sum = 0;

		// running another loop to iterate over the next elements until the required sum is not obtained
		for (int j = i; j < n; j++) {

			// if at any time , the sum exceeds k , break the loop.
			if (sum > k)break;
			sum += arr[j];

			// check for the maxlength
			if (sum == k) maxsubarr = max(j - i + 1, maxsubarr);

		}
	}

	return maxsubarr;

	// TC --> O(N*2) (running two nested loops both for max n times )
	// SC --> O(1) (no extra space required)
}




// Bettter Approach --> Using Hashmap (this approach becomes optimal if arr contains negative elements)
int longestSubarray3(vector<int> & arr, long long k) {
	int n = arr.size();
	long long sum = 0;
	int maxlength = 0;
	map<long long, int> prefixSum;

	for (int i = 0; i < n; i++) {

		//calculate the prefix sum till index i:
		sum += arr[i];

		// if the sum = k, update the maxLen:
		if (sum == k) {
			maxlength = max(maxlength, i + 1);
		}

		// calculate the sum of remaining part i.e. x-k:
		long long rem = sum - k;


		//Calculate the length and update maxLen:
		if (prefixSum.find(rem) != prefixSum.end()) {
			int len = i - prefixSum[rem] ;
			maxlength = max(maxlength, len);
		}

		//Finally, update the map checking the conditions:
		if (prefixSum.find(sum) == prefixSum.end()) {
			prefixSum[sum] = i;
		}

	}

	return maxlength;
	// TC --> for searching in the map
	//              --> in unordered map searching takes O(1) in avg case
	// 					but in worst case it can go upto O(n) --> O(n^2)
	//              --> in ordered map searching takes O(logn) --> O(nlogn)
	// SC --> O(n) as we are using a hash map data structure
}



// Optimal Approach --> using two pointer method
int longestSubarray(vector<int> &arr, long long k) {
	int maxlen = 0;
	int n = arr.size();
	int left = 0, right = 0;
	long long sum = arr[0];

	while (right < n ) {

		// if sum > k, reduce the subarray from left
		// until sum becomes less or equal to k:
		while (left <= right && sum > k) {
			sum -= arr[left];
			left++;
		}

		// if sum = k, update the maxLen i.e. answer:
		if (sum == k) {
			maxlen = max(maxlen, right - left + 1);

		}

		// Move forward thw right pointer:
		right++;
		if (right < n) sum += arr[right];
	}

	return maxlen;
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
// 	for (int i = 0; i < n; i++) {
// 		cout << arr[i] << " ";
// 	}
// 	cout << endl;
// }