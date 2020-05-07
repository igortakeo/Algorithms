#include <bits/stdc++.h>
#define MAX 200005
#define MAXLEVEL 20
using namespace std;
/*
 * LCA using sparce table
 * 
 * Precomputation: O(nlogn)
 * Answering each query: O(logn) 
 * 
 */ 


vector<int> tree[MAX];
int depth[MAX];
int parent[MAX][MAXLEVEL]; //stores in parent[v][i] the 2^i th parent of v

//Time Complexity: O(n)
void dfs(int v, int prev){
	
	depth[v] = depth[prev] + 1;
	parent[v][0] = prev;
	
	for(int i=0; i<tree[v].size(); i++){
		int u = tree[v][i];	
		if(u != prev) dfs(u, v);
	}
	
}

//Time Complexity: O(nlogn)
void precomputeSM(int n){
		
	for(int i=1; i<=ceil(log2(n)); i++){
		for(int j=1; j<=n; j++){
			if(parent[j][i-1] != -1){
				parent[j][i] = parent[parent[j][i-1]][i-1];	
			}
		}
	}
	
}

//Time Complexity: O(logn)
int lca(int v, int u, int n){
	
	if(depth[v] < depth[u]) swap(u,v);		
	
	int diff = depth[v] - depth[u];
	
	//Doing depth[v] == depth[u]
	for(int i=0; i<=ceil(log2(n)); i++){
		if((diff >> i)&1) v = parent[v][i];
		//is equal (diff/2^i)%2 != 0		
	}
	
	for(int i=ceil(log2(n)); i>=0; i--){
		if(parent[u][i] != parent[v][i]){
			u = parent[u][i];
			v = parent[v][i];
		}	
	}
	
	return parent[u][0];
}

int main(){
	
	memset(parent, -1, sizeof parent);
	
	int n, m, x, y;
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	
	dfs(1, 0);
	precomputeSM(n);
	
	for(int i=1; i<=n; i++){
		for(int j=0; j<=ceil(log2(n)); j++) cout << parent[i][j] << ' ';
		cout << endl;
	}
	
	cout << lca(6,10, n) << endl;
	
	return 0;
}
