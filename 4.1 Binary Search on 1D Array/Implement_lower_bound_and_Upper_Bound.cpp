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
	cout << lower_bound(arr.begin(), arr.end(), x) - arr.begin() << " ";
	cout << upper_bound(arr.begin(), arr.end(), x) - arr.begin() << endl;
	int ans = lowerBound(arr, x);
	int ans2 = upperBound(arr, x);

	cout << ans << " " << ans2 << endl;

}