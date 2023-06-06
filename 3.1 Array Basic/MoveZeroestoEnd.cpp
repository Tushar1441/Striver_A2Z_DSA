#include <bits/stdc++.h>
using namespace std;


// Brute Forced Approach-->
/*

	Create a temp array of length input array.

	Traverse through array and if a non zero elements encounter then
	put this element in the temp array at zero index and increment index
	Fill the zeros in remaining places of temp array
	    int temp[n];
        int k=0;
        for (int i=0;i<n;i++){
            if (arr[i]!=0){
                temp[k]=arr[i];
                k++;
            }
        }

        while (k<n){
            temp[k]=0;
            k++;
        }

        for(int i=0;i<n;i++)
        {
            cout<<temp[i]<<" ";
        }
    }

*/

void moveZeroestoEnd(vector<int> &arr, int n) {
	int n = arr.size();
	if (n == 1)return;
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) {
			arr[index] = arr[i];
			index++;
		}
	}

	for (int i = index ; i < n; i++) {
		arr[i] = 0;
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, k, temp;
	cin >> n ;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;
	}
	moveZeroestoEnd(arr, n
	               );
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

