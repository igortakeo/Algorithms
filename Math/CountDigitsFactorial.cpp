#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

/*
 * Dado um n! a função findDigits
 * retorna quantos digitos tem o fatorial
 * de n.
 * 
 * Complexidade : O(1)
 * 
 */ 

long long findDigits(int n) { 
    if (n < 0) return 0; 
    if (n <= 1) return 1; 
  
    double x = ((n * log10(n / M_E) + log10(2 * M_PI * n) / 2.0)); 
  
    return floor(x) + 1; 
} 

int main(){

	fastcin
		      
	return 0;
}
