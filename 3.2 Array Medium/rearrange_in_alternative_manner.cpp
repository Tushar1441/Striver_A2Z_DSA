#include <bits/stdc++.h>
using namespace std;


// Brute Force Solution --> Segregate the pos and neg elements in different temporary arrays
// and then arrange/put them in the array alternatively
void rearrangeArray1(vector<int> &arr) {
	int n = arr.size();
	vector<int> pos;
	vector<int> neg;

	// filling the neg and pos arrays
	for (int i = 0; i < n; i++) {
		if (arr[i] >= 0)pos.push_back(arr[i]);
		else neg.push_back(arr[i]);
	}

	// updating the array
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)arr[i] = pos[i / 2]; //pos elements at even index
		else arr[i] = neg[i / 2]; // neg elements at odd index
	}

	// TC --> O(n) + O(n)
	// Sc --> O(n)


	// Note --> if number of pos and neg elements in the array is not equal then
	// updating the array
	/*
		int i = 0, j = 0, k = 0;
		while (i < pos.size() && j < neg.size()) {
			if (k % 2 == 0) {
				arr[k] = pos[i]; i++;
			}

			else {
				arr[k] = neg[j];
				j++;
			}

			k++;
		}

		while (i < pos.size()) {
			arr[k] = pos[i];
			i++;
			k++;
		}

		while (j < neg.size()) {
			arr[k] = neg[j];
			j++; k++;
		}
	*/
}


// Optimal Approach --> we can reduce one for loop from the brute force solution
vector<int> rearrangeArray(vector<int> &arr) {
	int n = arr.size();
	vector<int> ans(n, 0);
	int posindex = 0, negindex = 1;

	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			ans[posindex] = arr[i];
			posindex += 2;
		}

		else {
			ans[negindex] = arr[i];
			negindex += 2;
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
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	vector<int> ans = rearrangeArray(arr);

	for (int i = 0; i < n; i++)cout << ans[i] << " ";
	cout << endl;

}