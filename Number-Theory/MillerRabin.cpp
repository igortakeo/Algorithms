#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mulmod(ll a, ll b, ll mod) { 
    ll res = 0;  
    a = a % mod; 
    while (b > 0) { 
        if (b % 2 == 1) res = (res + a) % mod; 
  
        a = (a*2) % mod; 
  
        b /= 2; 
    } 
    return res % mod; 
}

ll powermod(ll x, ll y, ll p) {
	 
    ll res = 1;       
    x = x % p;   
    
    while (y > 0) { 
        if (y & 1) res = mulmod(res, x, p); 
  
        y = y>>1;  
        x = mulmod(x, x, p); 
    } 
    return res; 
}  

bool MillerTest(ll d, ll n, ll a){
		
	//Compute (a^d)%n;
	ll x = powermod(a, d, n);

	if(x==1 or x==n-1) return true; //is prime
	
	//run r-1 times 
	while(d != n-1){
		x = mulmod(x, x, n);	
		d*=2;
		if(x == 1) return false; //is composite
		if(x == n-1) return true; //is prime 
	}
	
	return false;
}


bool isPrime(ll n){
	
	ll a[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	
	if(n<=1 or n==4) return false;
	if(n<=3) return true;
	
	//Find d such that n-1 = (2^r)*d
	ll d = n-1;
	while(d%2 == 0) d/=2;

	for(int i=0; i<12;i++){
		if(a[i] == n) break;
		if(!MillerTest(d, n, a[i])) return false;
	}
	
	return true;
}


int main(){
	
	//n: number that will be verified
	ll n;
	cin >> n;
	
	string ans;
	
	(isPrime(n)) ? ans = "YES" : ans = "NO";
	
	cout << ans << endl;
	
	return 0;
}
