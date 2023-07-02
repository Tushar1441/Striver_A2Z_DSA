#include <bits/stdc++.h>
using namespace std;

class MinStack {
    vector<int> arr, minIdx;
public:

    void push(int val) {
        if (minIdx.empty() || val < arr[minIdx.back()]) {
            minIdx.push_back(arr.size());
        }
        arr.push_back(val);
    }

    void pop() {
        arr.pop_back();
        if (minIdx.back() == arr.size())minIdx.pop_back();
    }

    int top() {
        return arr.back();
    }

    int getMin() {
        return arr[minIdx.back()];
    }

    int size() {
        return arr.size();
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    MinStack st(3);

    st.push(1);
    st.push(2);
    cout << st.top() << endl;
    st.push(3);
    st.push(4);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;

}