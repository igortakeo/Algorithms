#include <bits/stdc++.h>
#define MAX 100100
using namespace std;

//Encontra a arvore geradora minima (subconjunto de arestas que contem todos os vertices e possui peso minimo)

struct edges{ //struct aresta x = vertice_1, y = vertice_2 e weight = peso
	int x, y, weight;
};

bool compare(edges a, edges b){ //funcao compare para o sort, ordenar pelo peso da aresta
	return a.weight < b.weight;
}

vector<edges>edges_kruskal; //vetor de arestas
vector<edges>mst; //arvore geradora minima
int number_vertex, dist[MAX], father[MAX]; //numero de vertices e vetores para o union find
//----------Unio Find-------------
int find(int u){
	if(father[u] == u) return u;
	return father[u] = find(father[u]);
}

void join(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(dist[x] > dist[y])father[y] = x;
	else if(dist[y] > dist[x])father[x] = y;
	else {father[y]=x; dist[x]++;}
}
//--------------------------------
int kruskal(){ // retorna o custo total da arvore geradora minima
	int cost=0;
	sort(edges_kruskal.begin(), edges_kruskal.end(), compare); //ordenando os vertices pelo peso
	
	for(auto v : edges_kruskal){
		if (find(v.x) == find(v.y)) continue; //se os dois vertices tiverem o mesmo pai nao acontece nada	
		join(v.x, v.y); //unindo os dois vertices no mesmo conjunto
		mst.push_back(v); //colocando a aresta na arvore geradora minima
		cost += v.weight; //somando o peso no custo total 
		if(mst.size() == number_vertex-1)break; //se na arvore geradora minima conter number_vertex-1 arestas quer dizer que o algoritmo acabou
	}
	
	return cost;
}

