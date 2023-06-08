#include <bits/stdc++.h>
using namespace std;



// Approach --> If element is found , do not return the index instead move to the left half
// looking for previous iteration of target element
int firstOccurence(vector<int> &arr, int target) {
	int ans = -1;
	int low = 0;
	int high = arr.size() - 1;

	while (low <= high) {

		int mid = low + (high - low) / 2;

		if (arr[mid] >= target) {
			if (arr[mid] == target) {
				ans = mid;
			}
			high = mid - 1;
		}

		else {
			low = mid + 1;
		}
	}

	return ans;
}



// In this problem, just move towards the right half
int lastOccurence(vector<int> &arr, int target) {
	int ans = -1;
	int low = 0;
	int high = arr.size() - 1;

	while (low <= high) {

		int mid = low + (high - low) / 2;

		if (arr[mid] <= target) {
			if (arr[mid] == target) {
				ans = mid;
			}
			low = mid + 1;
		}

		else {
			high = mid - 1;
		}
	}

	return ans;
}


// We can also find the first and last occureces with the help of lower bound and upper bound
// if the target is present in the array then first occurence == lowerbound
// and the last occurence will be the upperbound -1;

int lowerBound(vector<int> &arr, int target) {
	int low = 0;
	int high = arr.size() - 1;
	int ans = arr.size() ;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] >= target) {
			ans = mid;
			high = mid - 1;
		}

		else low = mid + 1;
	}

	return ans;
}

int upperBound(vector<int> &arr, int target) {
	int low = 0;
	int high = arr.size() - 1;
	int ans = arr.size();

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] > target) {
			high = mid - 1;
			ans = mid;
		}
		else low = mid + 1;
	}

	return ans;
}

pair<int, int> lastAndFirstOccurence(vector<int>arr, int n , int target) {
	int lb = lowerBound(arr, target);
	if (lb == n || arr[lb] != target) return{ -1, -1};
	return {lb, upperBound(arr, target) - 1};

}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, x, temp;
	cin >> n >> x;
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	int ans1 = firstOccurence(arr, x);
	int ans2 = lastOccurence(arr, x);
	pair<int, int> ans = lastAndFirstOccurence(arr, n, x);
	cout << ans.first << " " << ans.second << endl;

	cout << ans1 << " " << ans2 << endl;

}