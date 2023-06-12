#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach--> check for all the numbers in the array if it is majority element or not
// TC --> O(n^2)


// Better Approach -> hashing
vector<int> majorityElement1(vector<int> &arr) {
	int n = arr.size();
	vector < int> ans;
	map<int , int> mapp;
	int mini = int(n / 3) + 1;
	for (auto it : arr) {
		mapp[it]++;
		if (mapp[it] == mini) {
			ans.push_back(it);
		}

		if (ans.size() == 2)break;

	}

	return ans;

	// TC --> O(n*logn)  (if using an ordered map)
	// TC --> O(n) in best and average case and O(n^2) in worst case (if using unordered map)
	// SC --> O(n)
}


// Optimal Approach --> Extended Boyer Moore's Voting Algorithm

vector<int> majorityElement(vector<int> &arr) {
	int n = arr.size();
	vector<int> ans;
	int cnt1 = 0, cnt2 = 0;
	int el1, el2;

	for (int i = 0; i < n; i++) {
		if (cnt1 == 0 && arr[i] != el2) {
			el1 = arr[i];
			cnt1++;
		}

		else if (cnt2 == 0 && arr[i] != el1) {
			cnt2++;
			el2 = arr[i];
		}

		else if (arr[i] == el1)cnt1++;
		else if (arr[i] == el2)cnt2++;

		else {
			cnt1--;
			cnt2--;
		}
	}
	cout << el1 << " " << el2 << endl;

	cnt1 = 0; cnt2 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == el1)cnt1++;
		else if (arr[i] == el2)cnt2++;
	}


	int mini = int(n / 3) + 1;
	if (cnt1 >= mini)ans.push_back(el1);
	if (cnt2 >= mini)ans.push_back(el2);

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
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	vector<int> ans = majorityElement(arr);
	for (auto it : ans)cout << it << " ";
	cout << endl;
}