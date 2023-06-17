#include <bits/stdc++.h>
using namespace std;


void insert(stack<int> &s, int temp) {
	if ( s.empty() || s.top() <= temp) {
		s.push(temp);
		return;
	}

	int val1 = s.top();
	s.pop();
	insert(s, temp);
	s.push(val1);
}

void sort(stack<int> &s) {
	if (s.size() == 1)return;

	int temp = s.top();
	s.pop();
	sort(s);
	insert(s, temp);
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

	sort(s);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;

}