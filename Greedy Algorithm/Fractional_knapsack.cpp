#include <bits/stdc++.h>
using namespace std;

bool comp( pair<int, int> &x,  pair<int, int> &y) {
    double r1 = (double)x.second / (double)x.first;
    double r2 = (double)y.second / (double)y.first;
    return  r1 > r2 ;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), comp);

    int idx = 0;
    double ans = 0 ;

    while (w > 0) {

        if (w >= items[idx].first) {
            ans += items[idx].second;
            w -= items[idx].first;
            idx++;
        }
        else if (w > 0) {
            ans +=  w * ((double)items[idx].second / (double)items[idx].first) ;
            break;
        }
        cout << ans << endl;
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