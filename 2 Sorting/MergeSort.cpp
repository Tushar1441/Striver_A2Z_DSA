#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int high, int mid) {

	int size_of_left_array = mid - low + 1;
	int size_of_right_array = high - mid ;


	auto *leftArray = new int[size_of_left_array],
	*rightArray = new int[size_of_right_array];

	for (int i = 0; i < size_of_left_array; i++) {
		leftArray[i] = arr[low + i];
	}
	for (int i = 0; i < size_of_right_array; i++) {
		rightArray[i] = arr[mid + 1 + i];
	}

	int indexOfleftArray = 0;
	int indexOfrightArray = 0;
	int indexOfmergedArray = low;

	while (indexOfleftArray < size_of_left_array && indexOfrightArray < size_of_right_array) {
		if (leftArray[indexOfleftArray] <= rightArray[indexOfrightArray]) {
			arr[indexOfmergedArray] = leftArray[indexOfleftArray];
			indexOfleftArray++;
		}

		else {
			arr[indexOfmergedArray] = rightArray[indexOfrightArray];
			indexOfrightArray++;

		}

		indexOfmergedArray++;
	}


	while (indexOfleftArray < size_of_left_array) {
		arr[indexOfmergedArray] = leftArray[indexOfleftArray];
		indexOfleftArray++;
		indexOfmergedArray++;
	}

	while (indexOfrightArray < size_of_right_array) {
		arr[indexOfmergedArray] = rightArray[indexOfrightArray];
		indexOfrightArray++;
		indexOfmergedArray++;
	}

	delete[] leftArray;
	delete[] rightArray;
}

void MergeSort(int arr[], int low, int high) {
	if (low >= high)return;

	int mid = (high - low) / 2 + low;
	MergeSort(arr, low, mid);
	MergeSort(arr, mid + 1, high);
	merge(arr, low, high, mid);

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

	MergeSort(arr, 0 , n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}