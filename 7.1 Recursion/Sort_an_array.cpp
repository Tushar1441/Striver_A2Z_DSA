#include <bits/stdc++.h>
using namespace std;


void placeElement(vector<int> &arr, int idx) {
	if (idx == 0)return;

	if (arr[idx] < arr[idx - 1]) {
		swap(arr[idx], arr[idx - 1]);
		placeElement(arr, idx - 1);
	}
	else return;
}


void sort(vector<int> &arr, int n) {
	if (n == 1)return;

	sort(arr, n - 1);
	placeElement(arr, n - 1);

	// TC --> O(n^2) in worst case
}


// We can also perform recusion in another way-->
// By reducing the size of the array itself.

void insert(vector<int> &arr, int temp) {
	if (arr.size() == 0 || arr[arr.size() - 1] <= temp) {
		arr.push_back(temp);
		return;
	}


	int val1 = arr[arr.size() - 1];
	arr.pop_back();
	insert(arr, temp);
	arr.push_back(val1);

}

void sort1(vector<int> &arr, int n) {
	if (n == 1)return;


	int temp = arr[n - 1];
	arr.pop_back();
	sort1(arr, n - 1);
	insert(arr, temp);
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, temp;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	sort1(arr, n);

	for (auto  it : arr)cout << it << " ";
	cout << endl;
}