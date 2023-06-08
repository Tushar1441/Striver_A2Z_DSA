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


// Optimal Approach --> without using extra space (do in-place swaps)
void moveZeroestoEnd(vector<int> &arr, int n) {
	int n = arr.size();
	if (n == 1)return;
	int index = -1;

	// storing first occurence of zero
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) return;

	for (int i = index + 1; i < n; i++) {
		if (arr[i] != 0) {
			swap(arr[index], arr[i]);
			index++;
		}
	}

	// TC --> O(n) (both loops run for total n times --> (0 -> index) + (index+1 -> n))
	// SC --> O(1)
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

