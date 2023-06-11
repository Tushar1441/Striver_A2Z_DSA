#include <bits/stdc++.h>
using namespace std;


int setRightmostUnsetBit(int n) {
	int check = n & (n + 1);
	if (check == 0)return n;
	int ans = n | n + 1;
	return ans;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, i;
	cin >> n;
	cout << setRightmostUnsetBit(n) << endl;

}