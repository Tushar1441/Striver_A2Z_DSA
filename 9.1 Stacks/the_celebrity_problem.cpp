#include <bits/stdc++.h>
using namespace std;



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n, k, temp;
    cin >> n >> k;

    vector<int>arr;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    vector<int>ans = maxSlidingWindow1(arr, k);
    for (auto it : ans) {
        cout << it << " ";
    } cout << endl;

}