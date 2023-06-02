#include <bits/stdc++.h>
using namespace std;



void recursiveInsertionSort(int arr[], int i, int n) {
    if (i == n)return;

    int j = i;
    while (j > 0 && arr[j] > arr[j - 1]) {
        swap(arr[j], arr[j - 1]);
    }

    return recursiveInsertionSort(arr, i + 1, n);
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

    recursiveInsertionSort(arr, 1, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}