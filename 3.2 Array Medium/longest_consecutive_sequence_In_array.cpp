#include <bits/stdc++.h>
using namespace std;


bool linearSerch(vector<int> &arr, int target) {
	int n = arr.size();
	for (int i = 0; i < n; i++) {
		if (arr[i] == target)return true;
	}
	return false;
}

// Brute Force Solution -- using two for loops
int longestSequence1(vector<int> &arr) {
	int n = arr.size();
	int longest = 1;

	for (int i = 0; i < n; i++) {
		int ele = arr[i] + 1;
		int current = 1;

		while (linearSerch(arr, ele) == true) {
			ele++;
			current++;
		}

		longest = max(current, longest);

	}

	return longest;

	// TC --> O(N^3) (the while loop's condition also takes O(n) to calculate)
	// and the while can run for O(n) in the worst case

	// SC --> O(1)
}



// Better Solution -- Sort the array and find the longest sequence
int longestSequence2(vector<int> &arr) {

	int n = arr.size();
	int longest = 1;
	int current = 1;

	sort(arr.begin(), arr.end()); // sort the array

	for (int i = 1; i < n; i++) {   // find the longest sequence
		if (arr[i] == arr[i - 1] + 1) {
			current++;
		}

		else if (arr[i] != arr[i - 1] + 1) {
			current = 1;
		}

		longest = max(longest, current);
	}

	return longest;

	// TC --> O(n*logn) + O(n)
	// SC --> O(1)


	// Note --> If the array contains duplicate elements then the above code will not work
	// We have to make some changes


	/* Longest Consecutive sequence (with duplicate elements) using sorting

		int n = arr.size();
		int longest = 0;
		int last_smaller = INT_MIN;
		sort(arr.begin(), arr.end());
		int current = 0;

		for (int i = 0; i < n; i++) {
			if (arr[i] - 1 == last_smaller) {
				current++;
				last_smaller++;
			}

			else if (last_smaller != arr[i]) {
				current = 1;
				last_smaller = arr[i];
			}

			longest = max(longest, current);
		}

		return longest;

	*/
}



// Optimal Solution --> using unordered set
int longestSequence(vector<int> &arr) {
	int n = arr.size();
	int longest = 0;
	unordered_set<int> st;

	// filling the set
	for (int i = 0; i < n; i++) {
		st.insert(arr[i]);
	}

	// Iterating the set
	for (auto it : st) { //if (arr[i] -1)/it exists in the arr/set then we will not go forward
		if (st.find(it - 1) == st.end()) {
			int cnt = 1;
			int x = it + 1; // looking if it+1 is available in the set
			while (st.find(x) != st.end()) {
				x++;
				cnt++;
			}

			longest = max(longest, cnt);
		}
	}

	return longest;

	// TC --> O(n) (for inserting in set) + O(n+n)
	// (the outer loop for O(n) and the inner while loop runs for n time in total n iterations)
	// SC --> O(n)
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

	int ans = longestSequence(arr);
	cout << ans << endl;

}