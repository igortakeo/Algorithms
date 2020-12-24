#include <bits/stdc++.h>
#define pb push_back
using namespace std;

// Pillai's Arithmetical Function search result to for(i = 1 until n) sum += gcd(i, n) 

vector<int> Divisors(int n){
	
	vector<int>v; 
	for(int i=1; i*i <= n; i++){
		if(n%i == 0){
			v.pb(i);		
			if(i != (n/i))v.pb(n/i);
		}
	}
	
	return v;
}


double phi(int n){
	double totient = n;
	
	for(int i=2; i*i<=n; i++){
		if(n%i == 0){
			while(n%i == 0) n/=i;
			totient *= (1.0 -(1.0/(double)i));
		}
	}
	if(n>1) totient *= (1.0 -(1.0/(double)n));
	return totient;
}

int main(){
	
	int n, ans = 0;
	cin >> n;
	
	vector<int> d = Divisors(n);
	
	 for(auto a : d){
		 ans += a*phi(n/a);
	 }
	 
	 cout << ans << endl;
	 
	return 0;
}
