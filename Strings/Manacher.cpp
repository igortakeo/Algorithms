#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000005 + 1

int P[SIZE*2];

/*
 * Mancher's Algorithm return the
 * Longest Palindrome Substring
 * 
 * Time Complexity : O(n)
 */ 

string convertToNewString(string s) {
    string newString = "@";

    for (int i = 0; i < s.size(); i++) {
        newString += "#" + s.substr(i, 1);
    }

    newString += "#$";
    return newString;
}

string longestPalindromeSubstring(string s) {
    string Q = convertToNewString(s);
    int c = 0, r = 0;                // current center, right limit

    for (int i = 1; i < Q.size() - 1; i++) {
		
		// find the corresponding letter in the palidrome subString
        int iMirror = c - (i - c);
		if(r > i) {
            P[i] = min(r - i, P[iMirror]);
        }

        // expanding around center i
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }

        // Update c,r in case if the palindrome centered at i expands past r,
        if (i + P[i] > r) {
            c = i;              // next center = i
            r = i + P[i];
        }
    }
		
	for(int i=1; i<Q.size() - 1; i++) cout << P[i] << ' ';
	cout << endl;	
		
    int maxPalindrome = 0;
    int centerIndex = 0;

    for (int i = 1; i < Q.size() - 1; i++) {
        if (P[i] > maxPalindrome) {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }

    cout << maxPalindrome << "\n";
    return s.substr((centerIndex - maxPalindrome) / 2, maxPalindrome);
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindromeSubstring(s) << endl;
    return 0;	
}
