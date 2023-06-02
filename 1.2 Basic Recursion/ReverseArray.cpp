#include <bits/stdc++.h>
using namespace std;


// Using Two Pointers -->

void reverse1(int l , int arr[], int r) {
	if (l >= r)return;

	swap(arr[l], arr[r]);
	reverse(l + 1, arr, r - 1);
}

// Using Single Pointer -->

void reverse2(int i, int arr[], int n) {
	if (i >= n / 2)return;

	swap(arr[i], arr[n - i - 1]);
	reverse(i + 1, arr, n);
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
	for (int i = 0; i < n; i++) cin >> arr[i];
	reverse(0, arr, n );
	for (int i = 0; i < n; i++)cout << arr[i] << " ";
	cout << endl;

}