#include <bits/stdc++.h>
using namespace std;

// This select() function takes the current select index and returns
// the index of the next min element

int select(int arr[], int i, int n) {
	int a = i;
	for (int j = i + 1; j < n; j++) {
		if (arr[a] > arr[j])a = j;
	}
	return a;
}


// This function takes the index return from the above function and
// swap the element on that position with the select index element

void SelectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		swap(arr[select(arr, i, n)], arr[i]);
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

	SelectionSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}