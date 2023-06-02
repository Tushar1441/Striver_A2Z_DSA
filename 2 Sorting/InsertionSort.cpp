#include <bits/stdc++.h>
using namespace std;

/*
In Insertion Sort, we divide the array into two parts - sorted and unsorted.

	-->The part which has been iterated over by the loop is the sorted one.
		and the remaining part is the unsorted one.
	-->We take an element from the unsorted part and put it into it's correct position
	   according to the sorted part by using simple swap function.
*/

void InsertionSort(int arr[], int n) {
	for (int i = 1; i < n ; i++) {

		int j = i;
		while (j > 0 && arr[j] < arr[j - 1]) {
			swap(arr[j], arr[j - 1]);
			j--;
		}

		// for (int i = 0; i < n; i++) {cout << arr[i] << " ";}
		// cout << endl;
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	InsertionSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}