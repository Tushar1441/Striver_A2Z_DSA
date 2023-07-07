#include <bits/stdc++.h>
using namespace std;


// Better Solution --> Using Monotone Stack
// We have to do some observation to find the max area histogram.
// a single histogram can expand to its area to right and left until it meet someone samller
// than itself on either side.
// So, we just can find the width by finding the NSR and NSL indexes for every index element.


// First Approach to perform the above alogorithm.
// Using two seperate passes, first find NSR/NSL an then find the NSL/NSR.
int largestRectangleArea(vector<int>& heights) {
	int n = heights.size();

	// we will calculate both nearest smaller to left and right.
	vector<int>nsl(n);
	vector<int>nsr(n);

	// initialise an empty stack.
	stack<int>st;

	// first calculate the nsl
	for (int i = 0; i < n; i++) {
		while (!st.empty() && heights[st.top()] >= heights[i]) {
			st.pop();
		}

		if (st.empty())nsl[i] = -1;
		else {
			nsl[i] = st.top();
		}

		st.push(i);
	}

	// remove everything present in the stack
	while (!st.empty())st.pop();


	// Step 2) fill the nsr array
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && heights[st.top()] >= heights[i]) {
			st.pop();
		}

		if (st.empty())nsr[i] = n;
		else {
			nsr[i] = st.top();
		}

		st.push(i);
	}


	// maximum area
	int maxi = 0;

	// now go through all the indexes to find the maximum.
	for (int i = 0; i < n; i++) {
		int curr = heights[i] * (nsr[i] - nsl[i] - 1) ;
		maxi = max(maxi, curr);
	}


	return maxi;

	// TC --> O(n+n) + O(n+n)  + O(n) == approx O(n)
	// Reason --> O(n+n) to find the nsr and again O(n+n) to find the nsl
	// O(n) to calculate the max area.
	// SC --> O(n+n+n) --> two arrays and one stack.
}



// we can also do this question using only one pass
// and without any extra array space
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

	// TC --> O(n) + O(n) == approx O(n)
	// SC --> O(n) --> one stack.
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
	cout << largestRectangleArea(nums1) << endl;
}
