#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach
// using two for loops try out all the combinations.
int reversePair1(vector<int>&arr) {
	int n = arr.size();
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] > 2 * arr[i])count++;
		}
	}

	return count;
	// TC --> O(N^2)
}



// ---------------------------------------------------------------------------

// Optimized Approach -->
// The intuition is similar to the count inversion problem

void merge(vector<int> &arr, int low, int mid, int high) {
	vector<int> temp; // temporary array
	int left = low;      // starting index of left half of arr
	int right = mid + 1;   // starting index of right half of arr

	//storing elements in the temporary array in a sorted manner//

	while (left <= mid && right <= high) {
		if (arr[left] <= arr[right]) {
			temp.push_back(arr[left]);
			left++;
		}
		else {
			temp.push_back(arr[right]);
			right++;
		}
	}

	// if elements on the left half are still left //

	while (left <= mid) {
		temp.push_back(arr[left]);
		left++;
	}

	//  if elements on the right half are still left //
	while (right <= high) {
		temp.push_back(arr[right]);
		right++;
	}

	// transfering all elements from temporary to arr //
	for (int i = low; i <= high; i++) {
		arr[i] = temp[i - low];
	}
}

int countPairs(vector<int> &arr, int low, int mid, int high) {
	int right = mid + 1;
	int cnt = 0;
	for (int i = low; i <= mid; i++) {
		while (right <= high && arr[i] > 2 * arr[right]) right++;
		cnt += (right - (mid + 1));
	}
	return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
	int cnt = 0;
	if (low >= high) return cnt;
	int mid = (low + high) / 2 ;
	cnt += mergeSort(arr, low, mid);  // left half
	cnt += mergeSort(arr, mid + 1, high); // right half
	cnt += countPairs(arr, low, mid, high); //Modification
	merge(arr, low, mid, high);  // merging sorted halves
	return cnt;
}

int reversePair(vector <int> & skill)
{
	return mergeSort(skill, 0, n - 1);
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, temp;
	cin >> n;;

	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	int ans = maxProduct(arr);
	cout << ans;
}