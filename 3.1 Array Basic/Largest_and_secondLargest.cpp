#include <bits/stdc++.h>
using namespace std;


/* For the largest element in an array, simply put a loop iterating over all the elements,
	and compute the largest element. */

int largestInArray(vector<int> &arr, int n) {
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max)max = arr[i];
	}

	return max;
}

/*
	For second largest element of an array, take two variables --
	--> one contains the current max element from the traversed array and initialise with INT_MIN
	--> another contains the second maximum element from the travesered array.
	If the max element is updated in an iteration, then the previous max element
	automatically becomes the second largest element in the traversed array.
*/

int secondMaximumInArray(vector<int> &arr, int n) {
	int max = INT_MIN, secmx = -1;

	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			secmx = max;
			max = arr[i];
		}
	}

	return secmx;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, k, temp;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;
	}
	cout << secondMaximumInArray(arr, n);

}