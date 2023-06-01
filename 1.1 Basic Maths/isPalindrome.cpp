#include <bits/stdc++.h>
using namespace std;

int reverseInteger(int N) {
	int x = N;
	int newnum  = 0;
	while (x != 0) {

		if ((newnum > INT_MAX / 10) || (newnum < INT_MIN / 10) ) return 0;
		newnum = newnum * 10 + (x % 10);
		x /= 10;

	}
	return newnum;
}

bool isPalindrome(int n) {
	if (n < 0 || (n != 0 && (n / 10) == 0)) return false;

	/* First Method -- Convert the number to a string and check the string indices

		string number = to_string(n);

		for (int i = 0; i < number.length() / 2; i++) {
			if (number[i] != number[number.length() - i - 1]) return false;
		}

		return true;

	*/


	/* Second Method -- Reverse the number and compare with the original number
		TC = O(N);
		SC = O(N);


		int x = reverseInteger(n);
		if (x == n) return true;
		return false;

	*/


	/* Third Approach - Intialise another integer and put reversed half digits
	   of the original number into the new integer and then compare both the halves
			TC = O(N);
		SC = O(N);

	int half = 0;

	while(n>half){
		half = half*10 + n%10;
		n/=10;
	}

	return (x==half || x==half/10) ;

	*/

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n;
	cin >> n;
	cout << isPalindrome(n) << endl;
}