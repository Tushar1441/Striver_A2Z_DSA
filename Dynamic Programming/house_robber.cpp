#include <bits/stdc++.h>
using namespace std;

// This house robber problem is similar to the last problem i.e. maximum_non_adjacant_sum.
// There is just one more constraint that we cannot pick the first and last element together
// because those two are also considered adjacant.

// The optimal solution would be to calculate the maxSum for two times-
// 1) first exclude the first element
// 2) exclude the last element
// return the maximum of the two.

int solve(vector<int>&arr) {
    if (arr.size() == 1)return arr[0];

    int prev2 = arr[0];
    int prev = max(arr[0] , arr[1]);

    for (int i = 2; i < n; i++) {
        int fs = prev2 + arr[i];
        int ss = prev;

        int curr = max(fs, ss);

        prev2 = prev;
        prev = curr;
    }

    return prev;

    // TC --> O(n)
    // SC --> O(n)
}

long long int houseRobber(vector<int>& valueInHouse)
{
    vector<int>temp1,temp2;
    int n = valueInHouse.size();
    if (n == 1)return valueInHouse[0];
    for (int i = 0; i < n; i++) {
        if (i != 0)temp1.push_back(valueInHouse[i]);
        if (i != n - 1)temp2.push_back(valueInHouse[i]);
    }


    return max(solve(temp1), solve(temp2) );

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

    cout << houseRobber(arr) << endl;

}