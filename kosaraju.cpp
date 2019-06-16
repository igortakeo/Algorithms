#include <bits/stdc++.h>
#define MAX 100100
using namespace std;

vector<int>edges[MAX], edges_T[MAX]; //grafo e grafo transposto
stack<int>st; //pilha
bool vis[MAX]; //vetor de visitados 
int number_vertex; //numero de vertices

void dfs(int u){ // uma dfs normal
	vis[u] = true;
	for(auto v : edges[u]) if(!vis[v]) dfs(v);
	st.push(v); //quando nao existe nenhum adjacente ao vertice 'u' ou todos os adjacentes foram visitados, o vertice eh colocado na pilha 
}

void dfs_t(int u){//dfs no grafo transposto
	cout << u << ' '; //printo o vertice 
	for(auto v : edges_t[u]) if(!vis[v]) dfs_t(v); // vejo se existe mais algum vertice fortemente conectado com 'u' 
}

void kosaraju(){ //execucao do kosaraju
	for(int i=1; i<= number_vertex; i++) if(!vis[i]) dfs(i); //construo a pilha
	memset(vis, false, number_vertex+1); //seto o vetor de visitados como "false"	
	while(!st.empty()){ //enquanto a pilha nao estiver fazia o while eh executado
		int w = st.top(); //pego o topo da pilha
		st.pop(); //retiro da pilha
		if(!vis[w]){dfs_t(w); cout << endl;} //se o vertice nao foi visitado executo a dfs no grafo transposto
	}	
}
