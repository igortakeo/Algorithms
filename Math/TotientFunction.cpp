#include <bits/stdc++.h>
using namespace std;

//Complexity : O(sqrt(n))

//Euler's Totient Function counts the number of integers between 1 and n inclusive which are coprime to n. 
//The sum of all values of Totient Function of all divisors of N is equal to N
//For 2 numbers A and B if GCD(A,B) = 1 then phi(A)*phi(B) = phi(A*b) 

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
	int n;
	cin >> n;
	cout << phi(n) << endl;
	
	return 0;
}
