#include <bits/stdc++.h>
#define MAX 100100
#define inf 0x3f3f3f3f //inf=1061109567
using namespace std;

//Caminho minimo em um grafo ponderado com peso negativo

struct edges{//struct aresta
	int x, y, weight; //x = vertice_1, y = vertice_2 e weight = peso
};

vector<edges>edges_bellford; //vetor de arestas
int dist[MAX]; //vetor de distancias
int number_vertex; //numero de vertices

void bellmanford(int u){
	
	for(int i=1; i<= number_vertex; i++) dist[i] = inf; //colocando todas as distancias como infinito
	dist[u] = 0; //setando como 0 apenas o vertice que iremos comecar

	for(int i=0; i < number_vertex-1; i++){ //rodando o algoritmo number_vertex-1
		bool flag = false;
		for(auto v : edges_bellford){
			if(dist[v.x] != inf && dist[v.x]+ v.weight < dist[v.y]){ //condicao para o relaxamento
				dist[v.y] = dist[v.x] + v.weight;
				flag  = true;
			}	
		}
		if(!flag)break; // se nao houver alteracao de custo em uma interacao o algoritmo esta finalizado
	}
	
	//verificando se ha um ciclo de peso negativo. O passo acima garante 
	//as distancias mais curtas se nao houver ciclo de peso negativo
		
	for(auto v : edges_bellford){
		// Se conseguimos relaxar quer dizer que ha um ciclo de peso negativo
		if(dist[v.x] != inf && dist[v.x]+ v.weight < dist[v.y]){cout << "Graph contains negative weight cycle" << endl; break;}		
	}	
			
}
