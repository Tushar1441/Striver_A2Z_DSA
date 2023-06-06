#include <bits/stdc++.h>
using namespace std;



// Brute Force Approach -- count the frequency of every element using 2 for loops

int majorityElement1(vector<int> &arr) {
	int n = arr.size();

	for (int i = 0; i < n; i++) // selecting element
	{
		int cnt = 0;    // count of arr[i] in the arr
		for (int j = 0; j < n; j++) {
			if (arr[i] == arr[j])cnt++;

			if (cnt == (n + 1) / 2)
			{
				return arr[i];
			}
		}
	}

	return -1;

	// TC --> O(n^2) -- two nested for loops
	// SC --> O(1)
}


// Better Approach --> Hashing
int majorityElement2(vector<int> &arr) {
	int n = arr.size();
	map<int, int>freq;

	for (int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}

	for (auto it : freq) {
		if (it.second >= (n + 1) / 2 ) {
			return it.first;
		}
	}
	return -1;

	// TC --> O(n) + O(m) , m--> unique elements in the arr.
	// If we use ordered map, then TC --> O(n + mlogm)

	// SC --> O(m)
}



// Optimal Approach --> Two pointer method
// Keeping the track of majority element in the traversed array
int majorityElement(vector<int> &arr) {
	int n = arr.size();
	int majorityEl = arr[0];
	int majorCnt = 1;

	for (int i = 1; i < n; i++) {


		if (arr[i] == majorityEl) {
			majorCnt++;
		}

		else {
			majorCnt--;
		}

		if (majorCnt == 0) {
			majorityEl = arr[i];
			majorCnt++;
		}

	}

	// return majorityEl;

	// Note --> If it is stated in the question itself that the array contains exactly one solution
	// then the majorityEl will always be the answer. But if it is not mentioned then we have to put a check
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == majorityEl) cnt++;
	}

	if (cnt > n / 2) return majorityEl;
	return -1;


	// TC --> O(n);
	// SC --> O(1);


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
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	int ans = majorityElement(arr);

	cout << ans << endl;

}