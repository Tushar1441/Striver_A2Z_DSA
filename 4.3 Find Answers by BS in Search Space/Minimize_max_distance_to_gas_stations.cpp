#include <bits/stdc++.h>
using namespace std;


// Brute Force Solution
long double minimiseMaxDistance(vector<int>&arr, int k) {

	int n = arr.size();

	// how many sections can be fit between each gas stations optimally
	vector<int>howmany(n - 1, 0);

	// to decide where to fill the gas station we have to check the max section length
	// and then place it there.
	for (int i = 0; i < k; i++) {
		int maxInd = -1;
		long double maxVal = -1;

		// finding max section length
		for (int j = 0; j < n - 1; j++) {
			long double diff = arr[j + 1] - arr[j];
			long double sectionLength = diff / (long double) (howmany[j] + 1);

			if (sectionLength > maxVal ) {
				maxVal = sectionLength;
				maxInd = j;
			}
		}

		// update sections in the chosen section
		howmany[maxInd]++;
	}


	// now find the max Section length from the array
	long double maxAns = -1;
	for (int i = 0; i < n - 1; i++) {
		long double diff = arr[i + 1] - arr[i];
		long long sectionLength = diff / (long double)(howmany[i] + 1);

		maxAns = max(maxAns, sectionLength);
	}

	return maxAns;

	// TC --> O(n*k) + O(n)
	// SC --> O(n)

}


// using priority queue
long double minimiseMaxDistance1(vector<int>&arr, int k) {
	int n = arr.size();
	// how many sections can be fit between each gas stations optimally
	vector<int>howmany(n - 1, 0);

	// priority queue will automatically put the biggest section length on top
	// in logn time complexity
	priority_queue<pair<long double, int>>pq;

	// put all the section lengths in the priority queue with indexes
	for (int i = 0; i < n - 1; i++) {
		pq.push({arr[i + 1] - arr[i], i});
	}


	for (int i = 0; i < k; i++) {
		auto tp = pq.top();
		pq.pop();

		// update the sections
		int secIdx = tp.second;
		howmany[secIdx]++;

		// push the new section length
		long double diff = arr[secIdx + 1] - arr[secIdx];
		long double sectionLength = diff / (long double) (howmany[secIdx] + 1);

		pq.push({sectionLength, secIdx});
	}

	return pq.top().first;

	// TC --> O(n*logn + k*logn)
	// SC --> O(n)
}



int numberOfStations(long double mid, vector<int>&arr) {
	int stations = 0;

	for (int i = 0; i < n - 1; i++) {

		int numberInBetween = (arr[i + 1] - arr[i]) / mid;
		if (arr[i + 1] - arr[i] == numberInBetween * mid)numberInBetween--;

		cnt += numberInBetween;
	}

	return cnt;
}

// optimised solution --> Using binary search
long double minimiseMaxDistance2(vector<int>&arr, int k) {
	int  n = arr.size();

	long double low = 0;
	long double high = 0;

	// high will be the max section length available in the arr
	for (int i = 0; i < n - 1; i++) {
		high = max(high, (long double) (arr[i + 1] - arr[i]));
	}


	long double diff = 1e-6;
	while (high - low > diff) {
		long double mid = (low + high) / 2.0;

		// number of gas stations with max section length as mid
		int gasStations = numberOfStations(mid, arr);

		if (gasStations > k) low = mid;
		else high = mid;
	}

	return high;
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

	cout << minimiseMaxDistance(arr, k) << endl;


}

