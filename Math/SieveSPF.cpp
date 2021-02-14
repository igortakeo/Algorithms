#include "bits/stdc++.h" 
using namespace std; 
#define MAXN 100001 

int spf[MAXN]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() { 
    for (int i=1; i<MAXN; i++)  spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) spf[i] = 2; 
    for (int i=3; i*i<MAXN; i++) { 
        if (spf[i] == i) { 
            for (int j=i*i; j<MAXN; j+=i){ 
               if (spf[j]==j) spf[j] = i;
            } 
        } 
    } 
}

int main(){
    sieve();
    for(int i=2; i<=50; i++){
        cout << i << ' ' << spf[i] << endl;
    }
    return 0;
} 
