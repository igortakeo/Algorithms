#include <bits/stdc++.h>
#define Max 10000001
using namespace std;
bool crivo[Max];

int main(){
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	long long N;
	cin >> N;
	
    for(long long i=2; i <= n; i++){
        if(!crivo[i]){
            ans++;
            for(long long j=i*i; j <= n; j+=i) crivo[j]=true;
        }
    }
    
	return 0;
}
