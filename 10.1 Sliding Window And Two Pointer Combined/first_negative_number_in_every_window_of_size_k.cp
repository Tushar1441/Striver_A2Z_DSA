#include <bits/stdc++.h>
using namespace std;

vector<int> negativeNumbers(vector<int>arr, int k) {
	int n = arr.size();
	vector<int>ans;
	queue<int>list;

	int right = 0, left = 0;

	while (right < n) {
		if (arr[right] < 0)list.push(arr[right]);

		if (right > k - 1) {
			if (list.front() == arr[left])list.pop();
			left++;
		}

		if (right - left == k - 1) {
			if (list.empty())ans.push_back(0);
			else ans.push_back(list.front());
		}

		right++;
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

	vector<int>ans = negativeNumbers(arr, k);
	for (auto it : ans)cout << it << " ";
	cout << endl;
}