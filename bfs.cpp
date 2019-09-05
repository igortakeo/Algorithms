#include <bits/stdc++.h>
#define N 100100
using namespace std;

vector<int>vertices[N]; //lista de adjacências.
int vis[N] = {0}; //0 para não visitado e 1 para visitado.

void bfs(int x){
	
	queue<int>fila;
	fila.push(x); //adiciona o primeiro vértice na fila.
	vis[x] = 1; //marcar o primeiro vértice como visitado. 
	
	int v  = 0, u  = 0;
	while(!fila.empty()){
			
		v = fila.front(); //primeiro elemento da fila.
		fila.pop(); //remover elemento da fila. 
		
		for(int i=0; i < vertices[v].size(); i++){
			u = vertices[v][i];
			if(vis[u] == 0){ //se u ainda não for visitado é adicionado na fila.
				fila.push(u);
				vis[u] = 1;
			}
		}
	}
}
