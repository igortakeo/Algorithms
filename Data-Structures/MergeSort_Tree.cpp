#include <bits/stdc++.h>
#define N 100005
using namespace std;

multiset<int> tree[4*N];

void update(int arr[], int l, int r, int i, int new_value, int cn){
	
	tree[cn].erase(tree[cn].find(arr[i]));
    tree[cn].insert(new_value);
    
    if (l != r) {
        int m = (l + r) / 2;
        if (i <= m)
            update(arr, l, m, i, new_value, cn*2+1);
        else
            update(arr, m+1, r, i, new_value, cn*2+2);
    } 
    else {
        arr[i] = new_value;
    }
	return;

}

//cn: current node
void build(int arr[], int l, int r, int cn) { 
  
    if (l == r){ 
        tree[cn].insert(arr[l]); 
        return; 
    } 
  
    int mid = (l + r)/2; 
    build(arr,l,mid,2*cn+1); 
    
    build(arr,mid+1,r,2*cn+2); 
  
    merge(tree[2*cn+1].begin(), tree[2*cn+1].end() , tree[2*cn+2].begin(), tree[2*cn+2].end(), inserter(tree[cn],tree[cn].begin())); 

} 
  
int query(int l, int r, int lb, int rb, int k, int cn) { 
  
    if (l >= lb && r <= rb) { 
		auto it = tree[cn].lower_bound(k);
        return (tree[cn].size() - distance(tree[cn].begin(), it )); 
    } 	
    else if(r < lb or l > rb) return 0;
  
    int mid = (l+r)/2; 
    return (query(l, mid, lb, rb, k, 2*cn+1) + query(mid+1, r, lb, rb, k, 2*cn+2)); 
}   
  
int main(){
	
	int n;
	cin >> n;
	
	int arr[n];
	
	for(int i=0; i<n; i++) cin >> arr[i];
	
	build(arr, 0, n-1, 0);
	
	
	/*
	cout << query(0, n-1, 0, 3, 6, 0) << endl; 
	update(arr, 0, n-1, 1, 9, 0);
	cout << query(0, n-1, 1, 5, 8, 0) << endl; 
	update(arr, 0, n-1, 1, 1, 0);
	cout << query(0, n-1, 1, 5, 8, 0) << endl; 
	*/
	return 0;
}
