#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int n, int k, int mid) {
	int cowCount = 1;
	int diff = 0;

	for (int i = 1; i < n ; i++) {
		diff += (arr[i] - arr[i - 1]);

		if (diff >= mid) {
			cowCount++;
			diff = 0;
		}
	}

	if (cowCount >= k)return true;
	return false;
}


int aggresiveCows(vector<int> &stalls , int k) {
	int n = stalls.size();
	if (n < k)return -1;

	sort(stalls.begin(), stalls.end());
	int low = 1;
	int high = stalls[n - 1];
	int ans = -1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		bool res = isPossible(stalls, n, k, mid);

		if (res == true) {
			ans = mid;
			low = mid + 1;
		}

		else high = mid - 1;
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
	int n, k, temp;
	cin >> n >> k;
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	cout << aggresiveCows(arr, k) << endl;


}

