#include <bits/stdc++.h>
using namespace std;


bool minCoins(vector<int>bills) {
	int n = bills.size();
	int fives = 0, tens = 0;


	for (int i = 0; i < n ; i++) {
		if (bills[i] == 5)fives++;

		else if (bills[i] == 10) {
			if (fives > 0) {
				tens++;
				fives--;
			}
			else return false;
		}

		else {
			if (fives > 0 and tens > 0) {
				tens--; fives--;
			}
			else if (fives > 3 )fives -= 3;

			else return false;
		}
	}

	return true;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, m, temp;
	cin >> n;

	vector<int>items;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		items.push_back(temp);
	}

	cout <<  minCoins(items) << endl;

}