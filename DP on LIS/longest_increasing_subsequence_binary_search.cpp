#include <bits/stdc++.h>
using namespace std;


int lengthOfLIS(vector<int>&arr) {
	int n = arr.size();
	vector<int>temp;
	temp.push_back(arr[0]);
	int len = 1;

	for (int i = 1; i < n; i++) {
		// arr[i] > the last element of temp array
		if (arr[i] > temp.back()) {
			temp.push_back(arr[i]);
			len++;
		}

		else {
			int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
			temp[idx] = arr[i];
		}
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

	cout << lengthOfLIS(arr) << endl;
}