#include <bits/stdc++.h>
using namespace std;


int maximumNumberOfStrings(vector<string>&words) {
	int n = words.size();
	map<string, int>mpp;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		if ( i != 0  && mpp[words[i]] != 0) {
			ans++;
			mpp[words[i]]--;
		}

		else {
			reverse(words[i].begin(), words[i].end());
			mpp[words[i]]++;
		}
	}

	return ans;
}

string join(string s1, string s2) {
	if (s1.back() == s2[0]) {
		s1.pop_back();
	}

	return s1 + s2;
}

int solve(int idx, vector<string>words, string bal) {
	if (idx == words.size())return bal.length();


	// before
	int before = solve(idx + 1, words, join(bal , words[idx]));

	// after
	int after = solve(idx + 1, words, join(words[idx] , bal));


	return min(after, before);
}

int GCD(int n, int m) {
	int a = max(n, m);
	int b = min(n, m);

	while (b > 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

int countPairs(vector<int>arr) {
	int ans = 0;
	int n = arr.size();
	for (int i = 0; i < n - 1; i++) {
		int number = arr[i];
		while (number >= 10)number /= 10;

		for (int j = i + 1; j < n; j++) {
			int number2 = arr[j] % 10;

			if (GCD(number, number2) == 1)ans++;
		}
	}

	return ans;
}

int minOperations(int num1, int num2) {
	if (num2 > num1)return -1;
	int operation = 0;


	while (num1 != 0) {
		cout << num1 << " ";
		num1 -= num2;
		operation++;

		if (num1 & 1) {
			num1 -= 1;
		}

		else {
			// cout << "hi" << endl;
			int bitno = log2(num1);
			num1 = (num1 & ~(1 << bitno)) ;
		}

	}
	return operation;
}


int numberOfGoodSubarraySplits(vector<int>& nums) {

	int n = nums.size();
	int ans = 1;
	int mod = (int)(1e9 + 7);
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] == 0) {
			count++;
		} else {
			ans *= (count + 1) % mod;
			count = 0;
		}
	}
	return ans;
}
// int joinStrings(vector<string>&words) {
// 	vector<vector<string>>dp()
// 	                    return solve(0, words, "");
// }


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int x = 3, y = 2, z = 2;
	vector<int>arr = {0, 1, 0, 0, 1};

	cout << minOperations(5, -21) << endl;
}