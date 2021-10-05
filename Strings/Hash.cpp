#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000009
using namespace std;


// Appropriate values of p
// only lowercase letters p= 31
// uppercase and lowercase letters p = 53

ll string_hash(string s){
    ll p = 31;
    ll hash = 0;
    ll exp = 1;
    ll n = s.size();
    for(int i=0; i<n; i++){
        hash = (hash + (s[i] - 'a' + 1)*exp)%MOD;
        exp = (exp*p)%MOD;
    } 
    return hash;
}

int main(){

    
    return 0;
}
