#include <bits/stdc++.h>

// Maximum Sum Subarray problem
// Time Complexity O(n)
// Space Complexity O(n)

using namespace std;

int kadane(int a[], int n){
	
    if(n == 0) return 0;

    int ans, maxCurrent;

    ans = maxCurrent = a[0];

    for(int i=1; i<n; i++){
        maxCurrent = max(maxCurrent+a[i], a[i]);
        if(maxCurrent > ans) ans = maxCurrent;
    }

	return ans;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)cin >> a[i];
    cout << kadane(a, n) << endl;

    return 0;
}
