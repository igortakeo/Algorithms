#include <bits/stdc++.h>

using namespace std;

int kadane(int a[], int n){
	
	int ans=0, max_end=0;
	int s=0, e=0, aux=0;
	for(int i=0;i<n;i++){
		max_end += a[i];
		if(max_end < 0){
            max_end = 0;
            aux = i + 1;
        }
        if(ans < max_end){
            ans = max_end;
            s = aux;
            e = i;
        }
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
