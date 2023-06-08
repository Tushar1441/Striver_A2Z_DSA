#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach -->
// Step 1 --> Generate all the posible permutation(N!) (Using Recursion)
// Step 2 --> Perform a linear search on the all permutation to find our given permuatation
// Step 3 --> Move to the next index and output the permutation.

// TC --> If we say on a high level, the TC will be of very high order
// To generate all the permutations --> TC = O(N! * N)
// To perform a linear search --> O(N! * N)
// So TC will be O(N! * N)
// SC --> O(N!) (Can be reduced to O(n) if we do not store all the permutations)


// Solution 2 only for C++ using built_in STL function
vector<int> nextPermutation1(vector<int> &arr) {
	int n = arr.size();
	next_permutation(arr.begin() , arr.end());
	return arr;
}



// Optimal Approach -->
// Intiution -->
// Step 1 -> Traversing from last idx to first idx, we will check if(arr[i] < arr[i+1])
// 			The idx returned in Step 1 will be the breakpoint for the next permutation.
// Step 2 -> Then find the element just greater than arr[i] in the rest of the array from(i,n-1);
// 			Swap the element returned in 2nd step with arr[i];
// Step 3 -> then reverse the array from arr[i+1],arr[n-1];

vector<int> nextPermutation(vector<int> &arr) {
	int n = arr.size();

	// Step 1: Find the break point:
	int ind = -1; // break point

	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] < arr[i + 1]) {
			// index i is the break point
			ind = i;
			break;
		}
	}

	// If break point does not exist:
	if (ind == -1) {
		// reverse the whole array:
		reverse(arr.begin(), arr.end());
		return arr;
	}


	// Step 2: Find the next greater element
	//         and swap it with arr[ind]:
	for (int i = n - 1; i > ind; i--) {
		if (arr[i] > arr[ind]) {
			swap(arr[i], arr[ind]);
			break;
		}
	}

	// Step 3: reverse the right half:
	reverse(arr.begin() + ind + 1, arr.end());

	return arr;

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
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	vector<int> ans = nextPermutation(arr);
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << endl;

}