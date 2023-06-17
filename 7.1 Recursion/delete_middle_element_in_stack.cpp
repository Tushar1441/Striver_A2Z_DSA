#include <bits/stdc++.h>
using namespace std;


void deleteMiddle(stack<int> &s, int k) {
	if (k == 1) {
		s.pop();
		return;
	}

	int temp = s.top();
	s.pop();
	deleteMiddle(s, k - 1);
	s.push(temp);
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
	stack<int> s;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		s.push(temp);
	}
	int k = n / 2 + 1;
	deleteMiddle(s, k);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;

}