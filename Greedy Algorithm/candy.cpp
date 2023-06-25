#include <bits/stdc++.h>
using namespace std;


// Greedy Approach Solution
// To give more candies than both the neighbours, we have to take into consideration
// both the left and right index at a particular index.

// For this purpose we can also break this problem into two sub problems
// first check only the left elements and in second traversal compare only the right elements
// then take the max of the candies from both the traversals.

int minCandy1(vector<int>&arr) {
    int n = arr.size();
    vector<int>ans(n, 1);
    vector<int>ans1(n, 1);

    // first check the left neighbours
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            // if element is greater than its left neighbour, then increse the candy count
            ans[i] = ans[i - 1] + 1;
        }
    }


    // check the right neighbour element
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1]) {
            // if element is greater than its left neighbour, then increse the candy count
            ans1[i] = ans1[i + 1] + 1;
        }
    }

    int candy = 0;
    for (int i = 0; i < n; i++) {
        candy += max(ans[i], ans1[i]);
    }

    return candy;

}


// The above solution can be done only using 1 for loop
int minCandy(vector<int>&arr) {
    int n = arr.size();
    vector<int>left(n, 1), right(n, 1);

    for (int i = 1; i < n; i++) {
        // first check the left neighbours
        if (arr[i] > arr[i - 1]) {
            left[i] = left[i - 1] + 1;
        }

        if (arr[n - i - 1] > arr[n - i ])
            right[n - i - 1] = right[n - i] + 1;
    }

    int candy = 0;
    for (int i = 0; i < n; i++) {
        candy += max(left[i], right[i]);
    }

    return candy;

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
    vector<int>arr;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    cout <<  minCandy(arr) << endl;

}