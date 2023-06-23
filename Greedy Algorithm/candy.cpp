#include <bits/stdc++.h>
using namespace std;


int minCandy(vector<int>&arr) {
    int ans = 1;
    int candy = 1;
    int n = arr.size();

    if (n > 1) {
        if (arr[0] > arr[1]) {ans = 2; candy = 2;}
    }

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            candy++;
        }

        else candy = 1;

        ans += candy;
    }

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
    vector<int>arr;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    cout <<  minCandy(arr) << endl;

}