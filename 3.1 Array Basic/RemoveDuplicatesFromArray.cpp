#include <bits/stdc++.h>
using namespace std;


// this brute force approach takes O(nlogn + n) time to execute the function.
// SC = O(n) --> (due to storage of set data structure)
int bruteForceRemoveDuplicates(vector<int> arr, int n) {
	// Let's create a set data structure and put all the unique elements of the array
	// into the set using insert function.length

	set<int> sets;
	for (int i = 0; i < n; i++) {
		// Every insertion takes O(logn) to execute.So,TC --> O(nlogn)
		set.insert(arr[i]);
	}

	// Now place the set elements into the array-->
	// This process takes O(n) to complete.
	int index = 0;
	for (auto it : sets) {
		arr[index] = it;
		index++;
	}

	// return the size of the unique array.
	return index + 1;

}


// This optimized approach performes only single traversal with two pointer approach
// TC = O(n) , SC = O(1)
int removeDuplicates(vector<int> &arr, int n) {
	// let a pointer indicating current size of unique elements array.
	int index = 0;

	// We iterate through the array and check--
	for (int i = 1; i < n  ; i++) {
		// if any unique element other than the arr[index] element is present in the array.
		if (arr[i] != arr[index]) {
			// if found --> then the size/index increases and the element is placed.
			index++; arr[index] = arr[i];
		}
	}


	// We have to return the size of new array i.e index+1.
	return index + 1;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n,  temp;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;
	}
	int k = removeDuplicates(arr, n);
	cout << k << endl;
	for (int i = 0; i < k; i++)cout << arr[i] << " ";
	cout << endl;

}