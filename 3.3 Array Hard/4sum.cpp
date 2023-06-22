#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach -- Using four nested for loops
vector<vector<int>> zeroSum1(vector<int> &arr) {
	int n = arr.size();
	set<vector<int>> st;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				for (int l = k + 1; l < n; l++) {
					if (arr[i] + arr[j] + arr[k] + arr[l] == 0) {
						vector<int> temp = {arr[i], arr[j], arr[k] , arr[l]};
						sort(temp.begin(), temp.end());
						st.insert(temp);
					}
				}
			}
		}
	}

	vector<vector<int>> ans(st.begin(), st.end());
	return ans;

	// TC --> O(n^4 + 4*k)  4*K to insert the quadruplets into vector
	// SC --> O(4*k) k is the number of quadruplets
}



// Better Approach --> Using Hashing
vector<vector<int>> zeroSum2(vector<int> &arr) {
	int n = arr.size();
	set<vector<int>> st;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			set <int> hashset;
			for (int k = j + 1; k < n; k++) {
				long long sum = arr[i] + arr[j];
				sum += arr[k];
				if (hashset.find(0 - sum) != hashset.end()) {
					vector<int> temp = {arr[i] , arr[j] , arr[k], (int)(0 - sum)};
					sort(temp.begin(), temp.end());
					st.insert(temp);
				}
				hashset.insert(arr[k]);
			}
		}
	}

	vector <vector<int>> ans(st.begin(), st.end());
	return ans;

	// TC --> O(n^3) * O(logm)  m is the number of elements in the set;
	// SC --> O(n) + O(quads)*2;
}



// Optimal Approach -->
// sort the array.
// Take two element as starting point and do binary search
// for the rest of the two elements.
vector<vector<int>> zeroSum(vector<int> &arr, int target) {
	int n = arr.size();
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
	for (int i = 0; i < n - 2; i++) {
		if ( i != 0 && arr[i] == arr[i - 1] ) continue;
		for (int j = i + 1; j < n; j++) {
			if (j != i + 1 && arr[j] == arr[j - 1])continue;
			int lo = j + 1, high = arr.size() - 1;
			while (lo < high) {
				long long sum = arr[i];
				sum += arr[j];
				sum += arr[lo];
				sum += arr[high];

				if (sum == target) {
					ans.push_back({arr[i], arr[j], arr[lo], arr[high]});

					while (lo < high && arr[lo] == arr[lo + 1]) lo++;
					while (lo < high && arr[high] == arr[high - 1]) high--;

					lo++; high--;
				}

				else if (sum < target)lo++;
				else high--;

			}
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
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	vector<vector<int>> ans = zeroSum(arr, 0);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[0].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}