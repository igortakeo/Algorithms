#include <bits/stdc++.h>
#define MAX 10000001
#define ll long long
#define fastcin cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
bool sieve[MAX];

/*
    Time Complexity: O(n*log(logn))
*/
int main(){
	fastcin
	ll n;
	cin >> n;
    for(ll i=2; i*i <= n; i++){
        if(!sieve[i]){
            for(ll j=i*i; j <= n; j += i){
                sieve[j]=true;
            }
        }
    }
    for(int i=2; i<= n; i++){
        if(!sieve[i]){
            cout << i << ' ';
        }
    }
    cout << endl;
	return 0;
}
