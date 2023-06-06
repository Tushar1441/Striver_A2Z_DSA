#include <bits/stdc++.h>
using namespace std;



// Brute Force Approach -- Just sort the array
void Sort1(vector<int> &arr) {
	int n = arr.size();
	sort(arr.begin(), arr.end());

	// Note -- This is not an expected solution
	// TC --> O(nlogn)
	// SC --> O(1)
}


// Better Approach --> Keeping the count of 0's, 1's and 2's.
//                     and then place them accordingly.

void Sort2(vector<int> &arr) {
	int n = arr.size();
	int cnt0 = 0, cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) cnt0++;
		else if (arr[i] == 1)cnt1++;
		else cnt2++;
	}

	int j = 0;
	while (j < cnt0) {
		arr[j] = 0;
		j++;
	}
	while (j < cnt0 + cnt1) {
		arr[j] = 1;
		j++;
	}
	while (j < cnt0 + cnt1 + cnt2) {
		arr[j] = 2;
		j++;
	}

	// TC --> O(2*n) -- first loop for the count and second for the updation
	// SC --> O(1)
}


// Optimal Approach -- Three pointer method(low,mid,high)
// arr[0….low-1] contains 0. [Extreme left part]
// arr[low….mid-1] contains 1.
// arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array

void Sort(vector<int> &arr) {
	int n = arr.size();
	int low = 0, high = n - 1, mid = 0;

	while (mid <= high) {

		if (arr[mid] == 1) {
			mid++;
		}

		else if (arr[mid] == 0) {
			swap(arr[low], arr[mid]);
			low++; mid++;
		}

		else {
			swap(arr[high], arr[mid]);
			high--;
		}
	}

	// TC --> O(n) if no swap happens
	// SC --> O(1)

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

	Sort(arr);

	for (auto it : arr) cout << it << " ";
	cout << endl;

}