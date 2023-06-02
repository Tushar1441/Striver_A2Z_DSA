#include <bits/stdc++.h>
using namespace std;


int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low ;
	int j = high - 1;

	while (i < j) {
		while (arr[i] <= pivot && i <= high - 1) {
			i++;
		}
		while (arr[j] > pivot && j >= low + 1) {
			j--;
		}

		if (i < j)swap(arr[i], arr[j]);
	}

	swap(arr[i], arr[high]);
	return i;
}


void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pIndex = partition(arr, low, high);
		quickSort(arr, low, pIndex - 1);
		quickSort(arr, pIndex + 1, high);
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

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}