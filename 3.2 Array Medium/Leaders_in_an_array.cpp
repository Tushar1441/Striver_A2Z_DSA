#include <bits/stdc++.h>
using namespace std;



// Optimal Approach --> Traversing from right and keeping track of the max element.
vector<int> leadersInArray(vector<int> &arr) {
	int n = arr.size();

	int leader;
	vector<int> leaders;
	int maxi = INT_MIN;
	int j = n - 1;
	while (j >= 0) {
		if (arr[j] > maxi) {
			maxi = arr[j];
			leaders.push_back(arr[j]);
		}

		j--;
	}

	return leaders;

	// TC --> O(n)
	// SC --> O(1)
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, temp;
	cin >> n ;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	vector<int> ans = leadersInArray(arr);
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << endl;

}