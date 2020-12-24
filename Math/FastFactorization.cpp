#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main(){
	
	//Fatores Primos 
	vector<pii>v;
	
	int n;
	cin >> n;
	
	for(int i=2; i*i <= n; i++){
		int c = 0;
		while(n%i == 0){
			c++;
			n/=i;
		}
		if(c != 0) v.push_back(pii(i, c));
	}
	if(n>1){ //se chegar nesse if o numero eh primo 
		v.push_back({n, 1});
	}

	return 0;
}
