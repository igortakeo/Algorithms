#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    The Lucas Theorem calculates the nCr % p in O(p^2*logp(n)) with p prime 
*/

//Calculate nCr%p 
ll BinomialCoefficientMOD(ll n, ll r, ll p){
    ll v[r+1];
    memset(v, 0, sizeof v);
    v[0] = 1;
    for(ll i=1; i <= n; i++){
        for(ll j = min(i, r); j > 0; j--){
            v[j] = (v[j] + v[j-1]) % p;
        }
    } 
    return v[r];
}

ll LucasTheorem(ll n, ll r, ll p){
    if(r == 0) return 1;
    return (LucasTheorem(n/p, r/p, p)*BinomialCoefficientMOD(n%p, r%p, p))%p;
}
    
int main(){

    ll n,r,p;
    cin >> n >> r >> p;
    cout << LucasTheorem(n,r,p) << endl;

    return 0;
}