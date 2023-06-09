#include <bits/stdc++.h>
using namespace std;

// Brute Force Appproach
int KthElementInTwoSortedArrays(vector<int> &array1, vector<int> &array2, int k) {
	int n = array1.size();
	int m = array2.size();

	int p1 = 0, p2 = 0, counter = 0, answer = 0;

	while (p1 < n && p2 < m) {
		if (counter == k) break;

		if (array1[p1] < array2[p2]) {
			answer = array1[p1];
			counter++;
			p1++;
		}
		else {
			answer = array2[p2];
			counter++;
			p2++;
		}
	}
	cout << answer << " " << counter << endl;
	if (counter != k) {
		if (p1 != n - 1)
			answer = array1[k - counter - 1];
		else
			answer = array2[k - counter - 1];
	}
	return answer;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, m, k, temp;
	cin >> n >> m >> k;
	vector<int> arr1;
	vector<int> arr2;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr1.push_back(temp);
	}

	for (int i = 0; i < m; i++) {
		cin >> temp;
		arr2.push_back(temp);
	}


	int ans = KthElementInTwoSortedArrays(arr1, arr2, k);
	cout << ans << endl;
}