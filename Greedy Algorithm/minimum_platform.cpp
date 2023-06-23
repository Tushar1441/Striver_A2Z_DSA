#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
//Take each interval of arrival and departure one by one and
// count the number of overlapping time intervals using two nested for loops
int minPlatforms1(int n, int arr[] , int dep[]) {
    // initialise ans with 1 platform
    int ans = 1;

    for (int i = 0; i < n; i++) {
        int curr = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] >= arr[j] && arr[i] <= dep[j]
                    || arr[j] >= arr[i] && arr[j] <= dep[i]) {
                curr++;
            }

        }
        ans = max(ans, curr);
    }

    return ans;
    // TC --> O(n^2)
}



// Optimized Approach -->
// Sort the arrival array and the departure array.
int minPlatforms(int n, int arr[], int dep[]) {

    // sort the arrays
    sort(arr, arr + n);
    sort(dep , dep + n);


    int ans = 1;
    int count = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j]) //one more platform needed
        {
            count++;
            i++;
        }
        else //one platform can be reduced
        {
            count--;
            j++;
        }
        ans = max(ans, count); //updating the value with the current maximum
    }

    return ans;

    // TC --> O(n*logn + n) for sorting the array and traversing the array
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

    vector<pair<int, int>>items;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        items.push_back(make_pair(x, y));
    }

    cout <<  maximumValue(items, n, m) << endl;

}