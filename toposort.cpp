#include <bits/stdc++.h>
#define MAX 100100
using namespace std;

vector<int>edges[MAX];//grafo
stack<int> topo; //na stack topo vai conter a ordenacao topologico, sendo o topo da pilha o primeiro elemento
bool vis[MAX];//vetor de visitados
int number_vertex; //numero de vertices

void dfs_topo(int u){
	vis[u] = true;
	for(auto v : edges[u]) if(!vis[v]) dfs_topo(v);	
	topo.push(u); //coloco na pilha quando nao existe adjacente ou todos foram visitados	
}

void topological_sorting(){
	for(int i=1; i<= number_vertex; i++) if(!vis[i]) dfs_topo(i); //ordenacao topologica vai passar por todos os vertices do grafo
}
