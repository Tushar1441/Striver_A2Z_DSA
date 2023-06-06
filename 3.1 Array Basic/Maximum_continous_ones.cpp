#include <bits/stdc++.h>
using namespace std;


int maximumContinousOnes(vector<int> &arr, int n) {

	// this variable contains the count of max consecutive ones in the array.
	int maxOnes = 0;
	// this variables maintains the count of current consecutive ones.
	int currentOnes = 0;

	for (int i = 0; i < n; i++) {

		// if 1 is encountered then update the current count and check the max count.
		if (arr[i]  == 1) {
			currentOnes++;
			maxOnes = max(currentOnes, maxOnes);
		}

		if (arr[i] != 1) {
			// if any element other than 1 is encountered then update the current count to 0.
			currentOnes = 0;
		}
	}

	return maxOnes;
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
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;
	}

	int ans = maximumContinousOnes(arr, n);
	cout << ans << endl;

}