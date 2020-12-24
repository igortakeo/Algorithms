#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

/*
Dado um n! e p(numero primo)
a função solve retorna o expoente de p
em n!, caso o n! fosse fatorado

*/
ll solve(ll n, ll p){
	
    ll res = 0;
    for (ll power = p ; power <= n ; power *= p) res += n/power;
    return res;
}

int main(){

	fastcin
  
	return 0;
}
