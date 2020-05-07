#include <bits/stdc++.h>
#define pb push_back
using namespace std;
//Algoritmo para conseguir todos os divisores de um Numero(n) em O(sqrt(n))

int main(){
	int n;
	cin >> n;
	vector<int>v; // neste vector contem todos os divisores do numero 'n'

	for(int i=1; i*i <= n; i++){
		if(n%i == 0){
			v.pb(i);		
			if(i != (n/i))v.pb(n/i);
		}
	}
	
	return 0;
}
