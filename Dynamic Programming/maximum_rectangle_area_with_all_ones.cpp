#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea1(vector<int>& heights) {
	int n = heights.size();

	// initialise an empty stack.
	stack<int>st;
	// maximum area
	int res = 0;


	for (int i = 0; i <= n; i++) {
		// find the next smaller element
		while (!st.empty() && heights[st.top()] >= heights[i]) {
			// store the element's index to be popped and calculate the area for it.
			int height = heights[st.top()];
			st.pop();

			int width;
			// if stack is empty we can the width is equal to i.
			if (st.empty())width = i;

			// else subtract the top element index.
			else {
				width = i - st.top() - 1;
			}

			res = max(res , width * height);


		}

		st.push(i);
	}

	return res;
}


int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m) {
	// Write your code here.
	vector<int>heights(m, 0);

	int maxi = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1)heights[j]++;
			else heights[j] = 0;

			int curr = largestRectangleArea1(heights);
			maxi = max(maxi, curr);
		}
	}

	return maxi;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, m, temp;
	cin >> n >> m;
	vector<vector<int>>nums1;
	for (int i = 0; i < n; i++) {
		vector<int>row;
		for (int j = 0; j < m; j++) {
			cin >> temp;
			row.push_back(temp);
		}
		nums1.push_back(row);
	}

	cout <<  maximalAreaOfSubMatrixOfAll1(nums1, n, m) << endl;
}
