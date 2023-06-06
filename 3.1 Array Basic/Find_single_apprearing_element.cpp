#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach
// For every element present in the array, we will do a linear search and count the occurrence.
// If for any element, the occurrence is 1, we will return it.
int getSingleElement1(vector<int> &arr) {
	int n = arr.size();

	//Run a loop for selecting elements:
	for (int i = 0; i < n; i++) {
		int num = arr[i]; // selected element
		int cnt = 0;

		//find the occurrence using linear search:
		for (int j = 0; j < n; j++) {
			if (arr[j] == num)
				cnt++;
		}

		// if the occurrence is 1 return ans:
		if (cnt == 1) return num;
	}

	//This line will never execute
	//if the array contains a single element.
	return -1;

// Time Complexity: O(N2), where N = size of the given array.
// Reason: For every element, we are performing a linear search to count its occurrence.
// The linear search takes O(N) time complexity. For N elements in the array, the total TC -> O(N^2).
// Space Complexity: O(1) as we are not using any extra space.
}




// Better Approach --> Using hash array
// In the previous approach, we were finding the occurrence of an element using linear search.
// We can optimize this using hashing technique.
// We can simply hash the elements along with their occurrences in the form of (key, value) pair.
// Thus, we can reduce the cost of finding the occurrence and hence the time complexity.
int getSingleElement(vector<int> &arr) {
	int n = arr.size();

	// First, we will find the maximum element(say maxElement) to know the size of the hash array.
	int maxi = INT_MIN;
	for (int i = 0; i < n; i++) {
		maxi = max(maxi, arr[i]);
	}

	// Declare hash array of size maxi+1
	// And hash the given array:
	vector<int> hash(maxi + 1, 0);
	for (int i = 0; i < n; i++) {
		hash[arr[i]]++;
	}

	//Find the single element and return the answer:
	for (int i = 0; i < n; i++) {
		if (hash[arr[i]] == 1)
			return arr[i];
	}

	return -1;

	// Time Complexity: O(N)+O(N)+O(N), where N = size of the array
	// Space Complexity: O(maxElement+1) where maxElement = the maximum element of the array.
	// Note -- if we use map data structure for hashing , then the TC will be O(n*logm) + O(m),
	// 		   and the SC will be O(m), where m is the size of hash map(n/2 +1).

}


// Better Approch --> Using Xor operator
// This approach is solely based on mathematics.
// if we xor all the elements in the array , then the duplicates will cancel out and
// the single appearing element will remain as the xor of the array

int getSingleElement3(vector<int> &arr) {
	int n = arr.size();
	int xor1 = 0;

	// xor all the elements..
	for (int i = 0; i < n; i++) {
		xor1 ^= arr[i];
	}

	return xor1;
}

// Optimal Approach --> Using Binary Search

int getSingleElement(vetcor<int> &arr) {
	int n = arr.size();

	if (n == 1)return arr[0];
	if (arr[0] != arr[1])return arr[0];
	if (arr[n - 1] != arr[n - 2])return arr[n - 1];
	int low = 1, high = n - 2;



	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] != arr[mid - 1] || arr[mid] ! arr[mid + 1]) {
			return arr[mid]
		}

		if (mid % 2 == 0 ) {
			if (arr[mid] == arr[mid + 1])low = mid + 1;
			else high = mid - 1;
		}

		else {
			if (arr[mid] == arr[mid + 1]) high = mid - 1;
			else low = mid + 1;
		}
	}
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, k, temp;
	cin >> n ;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;
	}
	int ans = getSingleElement(arr);
	cout << ans << endl;
	// for (int i = 0; i < n; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;
}