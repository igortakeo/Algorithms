#include <bits/stdc++.h>
#define MAX 2000001
using namespace std;

// Binary Indexed Tree or Fenwick Tree 
// Construction O(nlogn)
// Update O(logn)
// Query O(logn)  	
// Space Complexity O(n)

//Implementation of Prefix Sum

//To generalize each index in the tree store the cumulative sum of i-(i&-i)+1 to i (both inclusive).
//Example : if i = 1100(12) -i =0100(invert all bits and add one)  i&-i = 100(4)
//i&-i return the last set bit in i 

int BIT[MAX], n;

void update(int x, int new_value){
	for(; x <= n; x+= x&-x) BIT[x] += new_value;	
}

int query(int x){
	int sum = 0;
	for(; x > 0; x-=x&-x) sum += BIT[x];
	return sum; 	
}

int main(){
	
	cin >> n;
	// One-Based
	int v[n+1];
	
	for(int i=1; i<=n; i++){
		cin >> v[i];
		//Construction
		update(i, v[i]);	
	}

	return 0;
}
