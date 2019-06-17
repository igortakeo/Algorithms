#include <bits/stdc++.h>
#define MAX 100100
using namespace std;

vector<int>edges[MAX];//grafo
stack<int> topo; //na stack topo vai conter a ordenacao topologico ao contrario, sendo a base da pilha o primeiro elemento
bool vis[MAX];//vetor de visitados

void dfs_topo(int u){
	vis[u] = true;
	for(auto v : edges[u]) if(!vis[v]) dfs(v);	
	topo.push(u); //coloco na pilha quando nao existe adjacente ou todos foram visitados	
}
