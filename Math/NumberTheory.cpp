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
 * if a % m = c and b % m = c then (a-b)%m = 0
 * 
 *  for negative numbers (((a % b) + b) % b)
 * 
 * 
 */
 
 /* GCD and LCM Properties
  * 
  * gcd(P*N, P*M) = P*gcd(N,M)	
  * lcm(P*N, P*M) = P*lcm(N,M)	
  * 
  * lcm(P, M) = P*M/gcd(P,M)
  * Therefore gcd(P,M)*lcm(P,M) = P*M 
  * 
  * - gcd(m*a, m*b, m*c) = m*gcd(a,b,c)
  * - gcd(a+m*b, b) = gcd(a,b)
  * - gcd(a/m, b/m) = gcd(a,b)/m
  * - gcd(a,b) = gcd(a-b,b) if a > b 
  * - gcd(a,b) = gcd(a, b-a) if b > a	
  * 
  * if gcd(a,b) = 1 then
  * gcd(a*b, m) = gcd(a,m)*gcd(b,m)	
  * lcm(a*b, m) = (lcm(a,m)*lcm(b,m))/m
  * 
  * - lcm(a, gcd(a,b)) = a  
  * - gcd(a, lcm(a,b)) = a
  * - lcm(a, gcd(b,c)) = gcd(lcm(a,b),lcm(a,c))	
  * - gcd(a, lcm(b,c)) = lcm(gcd(a,b), gcd(a,c))
  * - gcd(lcm(a,b), lcm(b,c), lcm(c,a)) = lcm(gcd(a,b),gcd(b,c),gcd(c,a))
  * - lcm(gcd(a1,m), gcd(a2,m), ..., gcd(ak, m)) = gcd(lcm(a1,...,ak),m) 
  * - gcd(lcm(a1,m), lcm(a2,m), ..., lcm(ak, m)) = lcm(gcd(a1,...,ak),m) 
  * 
  * 
  */ 

#define ll long long

ll FasterExponentiation(ll x, ll n){
	if(n == 0) return 1;
	else if(n%2 == 0) return FasterExponentiation(x*x, n/2); // n is even 	
	else x*FasterExponentiation(x*x, (n-1)/2); //n is odd
}
//x <= 10^9
ll ModularExponentiation(ll x, ll n, ll m){
	if(n == 0) return 1;
	else if(n%2 == 0) return ModularExponentiation((x*x)%m, n/2, m);
	else return (x*ModularExponentiation((x*x)%m, (n-1)/2, m))%m;
}


ll mulmod(ll a, ll b, ll mod) { 
    ll res = 0;  
    a = a % mod; 
    while (b > 0) { 
        if (b % 2 == 1) res = (res + a) % mod; 
  
        a = (a * 2) % mod; 
  
        b /= 2; 
    } 
  
    return res % mod; 
}
//x <= 10^18
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

/*
  ax + by = c
  Diofantine Equation has solution only if 
  c%gcd(a,b)  = 0

  Extended Euclidean return the solution of a*x + b*y = gcd(a,b)
  d = gcd(a,b)

  To find a*x + b*y = c
  c = d*p
  x_0 = x*p and y_0 = y*p

  If Diofantine Euqation does have solution, then
  all solutions are given by:
  
  x_n = x_0 + (b/d)*t and y_n = y_0 - (a/d)*t

  x_0 : result x of extended euclidean
  y_0 : result y of extended euclidean
  d :  gcd(a,b)
  t: ranges over the integers

  x_n > 0 and y_n > 0

  t_1 = - x_0 / (b/d)
  t_2 =   y_0 / (a/d) 

  if t_1 < t_2 : t_1 < t < t_2
  else : t_2 < t < t_1
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
		int temp = x_ex;
		x_ex = y_ex;
		y_ex = temp-(A/B)*y_ex;
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
 //Time Complexity : O(M)
 
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
//Time Complexity : O(log(max(A, M)));

/*
* The third approach uses Fermat's Little Theorem
* 
* Theorem : modInverse = (A^(M-2))%M
* Note : M will be a prime
*/

ll modInverse(ll A, ll M){
   return ModularExponentiation(A,M-2,M);
}
//Time Complexity : O(log M);
  