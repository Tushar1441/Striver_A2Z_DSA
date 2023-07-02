#include <bits/stdc++.h>
using namespace std;


// int longestSubarrayLength(vector<int>&nums, int k) {
// 	int n = nums.size();

// 	int len = 0, ans = 0;
// 	for (int i = 0; i < n; i++) {
// 		if (nums[i] % 2 == 0 && nums[i] <= k) {
// 			len = 1;
// 			for (int j = i + 1; j < n; j++) {
// 				if (nums[j] % 2 != nums[j - 1] % 2 && nums[j] <= k) len++;
// 				else {
// 					i = j - 1;
// 					break;
// 				}
// 			}
// 		}
// 		ans = max(len, ans);
// 	}

// 	return ans;

// }

// const int N = 1e6 + 10;
// vector<bool>isPrime(N, 1);

// void sieve() {
// 	isPrime[0] = isPrime[1] = false;

// 	for (int i = 2; i * i <= N; i++) {
// 		if (isPrime[i] == true) {
// 			for (int j = i * i; j <= N; j += i) {
// 				isPrime[j] = false;
// 			}
// 		}
// 	}
// }


// vector<vector<int>> findPrimePairs(int n) {
// 	sieve();
// 	vector<vector<int>>ans;

// 	for (int i = 2; i <= n / 2; i++) {
// 		if (isPrime[i] && isPrime[n - i]) {
// 			ans.push_back({i, n - i});
// 		}
// 	}

// 	return ans;
// }



long long continuousSubarrays(vector<int>& nums) {


	int left = 0, right = 0;
	int max_num = nums[0], min_num = nums[0];
	int n = nums.size();

	long long count = 0;
	while (right < n) {
		max_num = max(max_num, nums[right]);
		min_num = min(min_num, nums[right]);

		if (max_num - min_num <= 2) {
			count += right - left + 1;
		}

		else {
			while (max_num - min_num > 2) {
				left += 1;
				max_num = *max_element(nums.begin() + left, nums.begin() + right + 1);
				min_num = *min_element(nums.begin() + left, nums.begin() + right + 1);
			}
			count += right - left + 1;
		}

		right ++;
	}


	return count;
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

	cout << continuousSubarrays(arr) << endl;
}