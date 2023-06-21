#include <bits/stdc++.h>
using namespace std;


bool comp(pair<int, int>&a, pair<int, int>&b) {
	return a.second < b.second;
}


// Optimal Solution --> Using Greedy Approach
// store the
// sort the arr on the basis of the ending time of the meetings.
int maxMeetings(int start[], int end[], int n) {
	vector<pair<int, int>>arr;
	for (int i = 0; i < n; i++) {
		arr.push_back(make_pair(start[i], end[i]));
	}

	sort(arr.begin(), arr.end(), comp);

	int last = arr[0].second;
	int ans = 1;

	for (int i = 1; i < n; i++) {
		if (arr[i].first > last) {
			ans++;
			// cout << last << endl;
			last = arr[i].second;
		}
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
	int n, temp;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	cout << maxMeetings(a, b, n);

}