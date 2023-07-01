#include <bits/stdc++.h>
using namespace std;

// Optimal Approach -> Using Sliding Window Algorithm
// flip all the bits we meet in our traversal.
// If k is exhausted then move the window until k becomes pos again and we
// can continue with our traversal.
int longestOnes(vector<int>arr, int k) {
	int n = arr.size();

	// answer variable (max consecutive ones length)
	int len = 0;

	// sliding pointers
	int left = 0, right = 0;


	while (right < n) {
		// if current element is 0 and k is also 0,
		// then move the left pointer until a flipped bit is not found.
		// then reverse flip the bit hypothetically and k is increased by 1.
		// so we can continue with our flipping opreration.
		if (arr[right] == 0 && k == 0) {
			while (left < right && arr[left] != 0) {
				left++;
			}
			left++; k++;
		}

		// if curr element is 0, flip it to 1 and subtract k.
		if (arr[right] == 0)k--;

		//update the length
		len = max(len, right - left + 1);
		right++;
	}

	return len;

	// TC --> O(N)
	// SC --> O(1)
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, k, temp;
	cin >> n >> k;
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	cout << longestOnes(arr, k) << endl;
}