#include <bits/stdc++.h>
using namespace std;

// brute force approach -->
// Step 1) make a new temp array of size m+n
// Step 2) Store all the sorted elements in the temp array from arr1 and arr2.
// Step 3) fill the arr1 and arr2 again with the temp array elements in order.
// TC --> O(N+m)
// SC --> O(n+m) but we want to avoid this.


// Optimized Approach 1)
// The Intiution is that if the last element of arr1 is smaller than
// the first element of arr2 then all the elements are in their correct position
// So, put a pointer on the last element and the first element of the arrays.

// while arr1[last] > arr2[start] then just swap the elements. and last--;start++.
void mergeArrays1(vector<int>&arr1, vector<int>&arr2, int m, int n) {

	int left = m - 1;
	int right = 0;

	//Swap the elements until arr1[left] is
	// smaller than arr2[right]:
	while (left >= 0 && right < m) {
		if (arr1[left] > arr2[right]) {
			swap(arr1[left], arr2[right]);
			left--, right++;
		}
		else {
			break;
		}
	}

	// Sort arr1[] and arr2[] individually:
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());

	// TC --> O(min(n,m)) + O(nlogn) + O(mlogm)
	// SC --> O(1)
}




// Optimized Solution 2)
// Intuition: Similar to optimal approach 1, in this approach,
// we will use two pointers i.e. left and right, and swap the elements
// if the element at the left pointer is greater than the element at the right pointer.

// But the placing of the pointers will be based on the gap value calculated.
// The formula to calculate the initial gap is the following:
// Initial gap = ceil((size of arr1[] + size of arr2[]) / 2)

void swapIfGreater(vector<int>arr1, vector<int>arr2, int ind1, int ind2) {
	if (arr1[ind1] > arr2[ind2]) {
		swap(arr1[ind1], arr2[ind2]);
	}
}


void mergeArrays(vector<int>arr1, vector<int>arr2, int n, int m) {
	// len of the imaginary single array:
	int len = n + m;

	// Initial gap:
	int gap = (len + 1) / 2;

	while (gap > 0) {
		// Place 2 pointers:
		int left = 0;
		int right = left + gap;

		while (right < len) {
			// case 1: left in arr1[]
			//and right in arr2[]:
			if (left < n && right >= n) {
				swapIfGreater(arr1, arr2, left, right - n);
			}
			// case 2: both pointers in arr2[]:
			else if (left >= n) {
				swapIfGreater(arr2, arr2, left - n, right - n);
			}
			// case 3: both pointers in arr1[]:
			else {
				swapIfGreater(arr1, arr1, left, right);
			}
			left++, right++;
		}
		// break if iteration gap=1 is completed:
		if (gap == 1) break;

		// Otherwise, calculate new gap:
		gap = (gap / 2) + (gap % 2);
	}

	// TC --> outer loop runs for log of gap i.e. m+n
	// inner loops runa for maximum n+m times.
	// So , TC --> O( (n+m) * log(m+n))
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int m, n, temp;
	cin >> m >> n;

	vector<int> arr1;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		arr1.push_back(temp);
	}

	vector<int> arr2;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr2.push_back(temp);
	}

	mergeArrays(arr1, arr2, m , n);

	for (auto it : arr1)cout << it << " ";
	cout << endl;
}