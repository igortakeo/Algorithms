#include <bits/stdc++.h>
#define ll long long
using namespace std;


vector<ll> sieve(ll n){
    vector<bool> vis(n+1, false);
    vector<ll>primes;
    for(ll i=2; i*i <= n; i++){
        if(!vis[i]){
            for(ll j=i*i; j <= n; j += i){
                vis[j]=true;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(!vis[i]) primes.push_back(i);
    }
    return primes;
}

vector<bool> segsieve(ll l, ll r){

    ll lim = sqrt(r);

    //Get all primes until sqrt(r);
    vector<ll>primes = sieve(lim);

    vector<bool>isPrime(r-l+1, true);
    
    for(ll i : primes){
        //mark all multiples of prime i
        for(ll j = max(i*i, (l+i-1)/i * i); j <= r; j+=i){
            isPrime[j-l] = false;
        }
    }
    if(l == 1) isPrime[0] = false;

    return isPrime;
}

int main(){

    ll l, r;
    cin >> l >> r;
    vector<bool> ans = segsieve(l, r);

    for(ll i = l; i <=r; i++){
        if(ans[i-l]){
            cout << i << ' ';
        }
    }
    cout << endl;

    return 0;
}