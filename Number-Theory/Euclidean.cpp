#include <bits/stdc++.h>
using namespace std;

int mdc(int a, int b){
  return (b == 0 ? a : mdc(b, a%b)); //b == 0 ? Caso sim, retorne a, caso não, retorne mdc(b, a%b)
}

int main(){
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	
	int a, b, ans_mdc, ans_mmc;
	
	ans_mdc = mdc(a, b);
	
	ans_mmc = (a*b)/mdc(a, b);


	return 0;
}
