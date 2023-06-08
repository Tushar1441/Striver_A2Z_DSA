#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int target) {
	int low = 0;
	int high = arr.size() - 1;
	int ans = arr.size() ;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] >= target) {
			ans = mid;
			high = mid - 1;
		}

		else low = mid + 1;
	}

	return ans;
}

int upperBound(vector<int> &arr, int target) {
	int low = 0;
	int high = arr.size() - 1;
	int ans = arr.size();

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] > target) {
			high = mid - 1;
			ans = mid;
		}
		else low = mid + 1;
	}

	return ans;
}



// Total Occurences will be last Occurence - first Occurence + 1
int totalOccurence(vector<int>arr, int n , int target) {
	int lb = lowerBound(arr, target);
	int ub = upperBound(arr, target);
	cout << lb << " " << ub << endl;
	if (lb == n || arr[lb] != target) return 0;
	return ub - lb ;

}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, x, temp;
	cin >> n >> x;
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	int ans = totalOccurence(arr, n, x);

	cout << ans  << endl;

}