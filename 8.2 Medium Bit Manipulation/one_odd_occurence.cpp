#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& arr)
{
	int n = arr.size();
	int xor1 = 0;
	for (int i = 0; i < n; i++) {
		xor1 ^= arr[i];
	}

	return xor1;

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
	cout << singleNumber(arr) << endl;
}