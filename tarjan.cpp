#include <bits/stdc++.h>
#define MAX 100100
using namespace std;

vector<int>edges[MAX];
stack<int>st;
int number_vertex, tarjan_time=0, time_discovery[MAX], low[MAX];
bool vis[MAX]; 

void dfs(int u){
	time_discovery[u] = low[u] = ++tarjan_time; //tempo de descoberta e low recebem o mesmo valor
	st.push(u); //coloca 'u' na pilha
	vis[u] = true; //marca como visitado
	for(auto v : edges[u]){ //vejo todos os adjacentes de 'u'  no grafo
		if(!time_discovery[v]){ //chamo a dfs se o vertice ainda nao foi visitado, ou seja, tempo de descoberta eh igual a 0
			dfs(v); 
			low[u] = min(low[u], low[v]); //pego o menor low entre 'u' e seu adjacente 'v' na volta da recursao
		}
		else if(vis[v]) low[u] = min(low[u], time_discovery[v]); //se o vertice ja foi visitado pego o menor low 
	}
	
	if(low[u] == time_discovery[u]){ //se low e o tempo de descoberta forem iguais quer dizer que achamos um grupo de componentes conexas
		int w = 0;
		while(st.top() != u){ //todos os vertices que estiverem em cima de 'u' na pilha(mesmo low) serao printados 
			w = st.top();
			cout << w << ' ';
			vis[w] = !vis[w];
			st.pop();
		}
		
		w = st.top();
		cout << w << endl;
		vis[w] = !vis[w];
		st.pop();
	}
	
}

void tarjan(){ //execucao do tarjan
	for(int i=0; i < number_vertex; i++){
		if(time_discovery[i] == 0) dfs(i);
	}
}
