#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach
// using two for loops try out all the subarrays.
int maxProduct1(vector<int>&arr) {
    int n = arr.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        int curr = 1;
        for (int j = i; j < n; j++) {
            curr *= arr[j];
            maxi = max(maxi, curr);
        }
    }

    return maxi;
    // TC --> O(N^2)
}



// Optimal Approach
// This approach is based on some observation.

// Idea is to find the maximum product from both sides,i.e,
// once in a forwarding direction and another in the backward direction.
int maxProduct(vector<int>&arr) {
    int n = arr.size();
    int prod = 1 ;

    bool isZero = 0;

    // calculate all the prefix products
    int maxPrefix = arr[0];
    for (auto it : arr) {
        prod *= it;

        if (it == 0) {
            isZero = true;
            prod = 1;
            continue;
        }

        maxPrefix = max(prod, maxPrefix);
    }

    prod = 1;


    // now calculating suffix products.
    int maxSuffix = arr[0];
    for (int i = n - 1; i >= 0 ; i--) {
        prod *= arr[i];

        if (arr[i] == 0) {
            isZero = true;
            prod = 1;
            continue;
        }

        maxSuffix = max(maxSuffix, prod);
    }


    int maxi = max(maxSuffix, maxPrefix);
    if (isZero)return max(maxi, 0);
    return maxi;


    // TC --> O(n + n)
    // SC --> O(1)
}




int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n, temp;
    cin >> n;;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    int ans = maxProduct(arr);
    cout << ans;
}