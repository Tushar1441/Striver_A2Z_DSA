#include <bits/stdc++.h>
using namespace std;

// Better Approach
int trap(vector<int>&height) {

	int n =  height.size();
	vector<int>maxLeft(n), maxRight(n), water(n);
	maxLeft[0] = height[0];
	maxRight[n - 1] = height[n - 1];

	for (int i = 1; i < n; i++) {
		maxLeft[i] = max(maxLeft[i - 1] , height[i]);
		maxRight[n - i - 1] = max(maxRight[n - i ], height[n - i - 1]);
	}

	int ans = 0;

	for (int i = 1; i < n - 1; i++) {
		water[i] = min(maxRight[i], maxLeft[i]) - height[i];
		ans += water[i];
	}

	return ans;

	// TC --> O(n)+O(n)
	// SC --> O(n)+O(n)+O(n)
}


// Most Optimal Approach --> Using Two Pointers
// We will traverse the landscape only once and will keep track of the maxLeft
// and the maxRight wall encountered.
int trap(vector<int> &height)
{
	int n = height.size();
	int left = 0;
	int right = n - 1;
	int res = 0;
	int maxleft = 0;
	int maxright = 0;
	while (left <= right)
	{
		// if leftwall is shorter
		if (height[left] < height[right])
		{
			// if the current wall is max from the left,then it cannot store water on its top
			if (height[left] > maxleft)
			{
				maxleft = height[left];
			}
			else
			{
				res = res + maxleft - height[left];
			}
			left++;
		}
		// if right wall is shorter
		else
		{
			// if the current wall is max from the right,then it cannot store water on its top
			if (height[right] > maxright)
			{
				maxright = height[right];
			}
			else
			{
				res = res + maxright - height[right];
			}
			right--;
		}
	}
	return res;
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
	cout << trap(nums1) << endl;
}
