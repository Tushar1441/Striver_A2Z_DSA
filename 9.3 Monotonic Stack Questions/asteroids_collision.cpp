#include <bits/stdc++.h>
using namespace std;

// if both the asteroids are running in same direction or first one is going to left
// and the next one is going to right, then they will never collide.
bool isDirectionSafe(int a, int b) {
	if (a < 0 && b < 0 || a > 0 && b > 0 || a > 0 && b < 0)return true;
	return false;

	// a is running to left and b is running to right
	// if(a<0 && b >0) return false;
}


vector<int> asteroidCollision(vector<int>& asteroids) {
	int n = asteroids.size();
	stack<int>st;

	for (int i = 0; i < n; i++) {

		if (!st.empty()) {
			while (!st.empty() && (abs(st.top()) < abs(asteroids[i])  && !isDirectionSafe(asteroids[i], st.top()))) {
				st.pop();
			}

			if (abs(st.top()) == abs(asteroids[i]) && !isDirectionSafe(asteroids[i], st.top())) {
				st.pop(); continue;
			}
		}

		if (st.empty() || isDirectionSafe(asteroids[i], st.top())) {
			st.push(asteroids[i]);
		}
	}

	vector<int>ans;

	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}

	reverse(ans.begin(), ans.end());
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
	vector<int>nums1;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		nums1.push_back(temp);
	}

	vector<int> ans = asteroidCollision(nums1);
	for (auto &it : ans) {
		cout << it << " ";
	} cout << endl;
}
