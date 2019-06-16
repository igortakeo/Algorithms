#include <bits/stdc++.h>
#define MAX 100100
using namespace std;

vector<int>edges[MAX], edges_T[MAX];
stack<int>st;
bool vis[MAX];
int number_vertex;

void dfs(int u){
	vis[u] = true;
	for(auto v : edges[u]) if(!vis[v]) dfs(v);
	st.push(v);
}

void dfs_t(int u){
	cout << u << ' ';
	for(auto v : edges_t[u]) if(!vis[v]) dfs_t(v);
}

void kosaraju(){
	for(int i=1; i<= number_vertex; i++) if(!vis[i]) dfs(i);
	memset(vis, false, number_vertex+1);	
	while(!st.empty()){
		int w = st.top();
		st.pop();
		if(!vis[w]){dfs_t(w); cout << endl;}
	}	
}
