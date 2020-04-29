/*
 * 
 * Modular Arithmetic
 * 
 * 
 * 1 - (a+b)%c = (a%c + b%c)%c
 * 2 - (a*b)%c = ((a%c) * (b%c))%c
 * 3 - (a-b)%c = ((a%c) - (b%c) + c)%c
 * 4 - (a/b)%c = ((a%c) * ((b^-1)%c))%c 
 * 
 * Note : b^-1 is the multiplicative modulo inverse of b and c
 * 
 * 
 */

#define ll long long

ll FasterExponentiation(ll x, ll n){
	if(n == 0) return 1;
	else if(n%2 == 0) return FasterExponentiation(x*x, n/2); // n is even 	
	else x* FasterExponentiation(x*x, (n-1)/2); //n is odd
}

ll ModularExponentiation(ll x, ll n, ll m){
	if(n == 0) return 1;
	else if(n%2 == 0) return ModularExponentiation((x*x)%m, n/2, m);
	else return (x*ModularExponentiation((x*x)%m, (n-1)/2, m))%m;
}

ll d, x, y;

void extendEucld(ll A, ll B){
	if(B == 0){
		d = A;
		x = 1;
		y = 0;
	}
	else{
		extendEucld(B, A%B);
		int temp = x;
		x = y;
		y = temp-(A/B)*y;
	}
}

/*
 * Modular multiplicative inverse
 *  (A*B)%M = 1
 * 	which the value the variable B ?
 * 	B in the range[1, M-1]
 * 	
 * - Existence of modluar multiplicative inverse
 * 	An inverse exists only when A and M are coprime i.e GCD(A, M) = 1
 *  
 * 
 */ 
 
 ll modInverse(ll A, ll M){
	 
	 A = A%M;
	 for(int B=1; B < M; B++){
		 if((A*B)%M == 1) return B; 
	 }
	 
 }
 Time Complexity : O(M)
 
 /*
  * A and M  are coprime i.e Ax + My = 1. In the extend
  * Eucledian algorithm, x is the modular multiplicative 
  * inverse of A under modulo M. Therefore, the answer is 
  * x. You can use the extend Eucledian algorithm  to find 
  * the multiplicative inverse.
  * 
  */
  
ll modInverse(ll A, ll M){
		
	  extendEucld(A, M);
	  return (x%M + M)%M; //x may be negative 
	  
}
  Time Complexity : O(log(max(A, M)));

  /*
   * The third approach uses Fermat's Little Theorem
   * 
   * Theorem : modInverse = (A^(M-2))%M
   * Note : M will be a prime
   */
   
   ll modInverse(ll A, ll M){
	   return ModularExponentiation(A,M-2,M);
   }
   Time Complexity : O(log M);
