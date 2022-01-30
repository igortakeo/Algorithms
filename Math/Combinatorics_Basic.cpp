#include <bits/stdc++.h>
#define ll long long
#define MAX 15
#define MOD 100000000
using namespace std;
/*
Simple Permutation: n!
Arrangement: n!/(n-p)!
Arrangement with Repetition: n^p
Combination: n!/(p!*(n-p)!)
Combination with Repetition: (n+p-1)!/(n-1)!*p!
*/


ll d_ex, x_ex, y_ex;
 
void extendEucld(ll A, ll B){
	if(B == 0){
		d_ex = A;
		x_ex = 1;
		y_ex = 0;
	}
	else{
		extendEucld(B, A%B);
		ll temp = x_ex;
		x_ex = y_ex;
		y_ex = temp-(A/B)*y_ex;
	}
}
 
ll modInverse(ll A, ll M){
	extendEucld(A, M);
	return (x_ex%M + M)%M; //x may be negative 
	  
}
 
 //BinomialCoefficient to large numbers.
ll BinomialCoefficient(ll n, ll p){
    
    if(n < p) return 0;
    
    ll bc = 1;
    //Using symmetry rule for binomial coefficient (C(n,q) = C(n,p) if q+p = n)
    if(p > n-p) p = n - p;
    //Calculating the binomial coefficient from simplify equation (n*(n-1)*...*(n-k+1))/(k*(k-1)*...1)
    for(ll i = 0; i < p; i++){
        ll k = n-i, l = i+1;
        bc = ((bc%MOD)*(k%MOD))%MOD; 
        bc = ((bc%MOD) * modInverse(l, MOD))%MOD;
    }
    return bc;
}
   
//Binomial Coefficient O(p) time
int BinomialCoefficient(int n, int p){

    if(n < p) return 0;

    int bc = 1;

    //Using symmetry rule for binomial coefficient (C(n,q) = C(n,p) if q+p = n)
    if(p > n-p) p = n - p;

    //Calculating the binomial coefficient from simplify equation (n*(n-1)*...*(n-k+1))/(k*(k-1)*...1)
    for(int i = 0; i < p; i++){
        bc = (bc*(n-i))/(i+1);
    }
    return bc;
}

//Construct Pascal Triangle in O(n^2) time 
int triangle[MAX][MAX];

void PascalTriangle(int n){

    for(int i = 0; i < n; i++){
        for(int j=0; j<=i; j++){
            if(i == j || j == 0) triangle[i][j] = 1;
            //Using the recurrence for the binomial coefficients (n p) = (n-1 p-1) + (n-1 p)
            else triangle[i][j] = triangle[i-1][j-1]+triangle[i-1][j]; 
        }

    }

}


/*
    Inclusion and Exclusion
*/

// Problem example: how many numbers between [1,n] are divisible by numbers in vector 'numbers' ?
// Complexity: O((2^n)*n)

ll CardinalityofSum(ll n, vector<ll>numbers){

    ll m = numbers.size();
    ll subsets = 1<<m;
    ll ans = 0;

    //This first 'for' generate all combinations of subsets 
    for(ll i=1; i < subsets; i++){
        ll d = 1; 
        ll number_setbits = __builtin_popcount(i); //Numbers of 1's in binary number i

        //Checking if 'j' number in 'numbers' belongs in subset 'i'
        for(ll j = 0; j<m; j++){
            if(i & (1<<j)){
                d *= numbers[j];
            }
        }

        //If number of set bits in 'i' is odd or even
        if(number_setbits & 1) ans += n/d;
        else ans -= n/d;
    }

    return ans;
}


int main(){
    return 0;
}
