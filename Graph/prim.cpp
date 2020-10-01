#include <bits/stdc++.h>
#define pii pair<int, int>
#define MAX 100100
using namespace std;

//Encontra a arvore geradora minima (subconjunto de arestas que contem todos os vertices e possui peso minimo)

struct edges{ //struct aresta x = vertice_1, y = vertice_2 e weight = peso
	int x, y, weight;
};

int number_vertex; //numero de vertices
bool vis[MAX]; //vetor de visitados
vector<pii>edges_prim[MAX]; //grafo de pair first = distancia e second = vertice
vector<edges>mst; //arvore geradora minima

int prim(int u){ //retorna o custo total da arvore geradora minima
	int cost=0;
	priority_queue<pii, vector<pii>, greater<pii>>queue; //criamos uma fila de prioridade onde o menor fica no topo, em outras palavras, um min heap
	for(int i=0; i < number_vertex-1; i++){	//arvore geradora minima tem number_vertex-1 arestas
		vis[u] = true; //marcando como visitado
		for(auto v : edges_prim[u]){ //colocando na fila de prioridades todos os adjacentes que nao foram visitados
			if(!vis[v.second]) queue.push(v);	
		}
		while(vis[queue.top().second]) queue.pop(); //se o vertice ja foi visitado eh retirado da fila
		edges w; //aresta que irá ser colocada no mst
		w.x = u; //vertice de saida
		w.y = queue.top().second; //vertice de chegada
		mst.push_back(w); //colocando a aresta na arvore geradora minima
		cost += queue.top().first; //somando no custo total
		u = queue.top().second; //indo para o proximo vertice
		queue.pop();
	}
	
	return cost;
}


