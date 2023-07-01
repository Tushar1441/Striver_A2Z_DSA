#include <bits/stdc++.h>
using namespace std;


// Optimal Approach --> Using Sliding Window Algorithm
// Using a map data structure, store the count of every every element.
int totalFruits(int n, vector<int> &arr) {

	int len = 0;
	// initialise a unordered map ds.
	unordered_map<int, int>mpp;

	// sliding pointers
	int left = 0, right = 0;

	while (right < n) {
		// update the frequency.
		mpp[arr[right]]++;

		// if map contains more than 2 elements,
		// then we need to decrease the count, because we can take only 2 unique fruits.
		if (mpp.size() > 2) {
			mpp[arr[left]]--;
			// if freq of any element becomes 0 after subtracting,
			// then erase the element from the map.
			// because it will increase the size without actually
			// holding anything.
			if (mpp[arr[left]] == 0) {
				mpp.erase(arr[left]);
			}

			left++;
		}

		// update the length to current window size if possible.
		len = max(len, right - left + 1);
		right++;
	}

	return len;
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
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	cout << totalFruits(n, arr) << endl;
}