#include <bits/stdc++.h>
#define inf 0x3f3f3f3f //inf=1061109567
#define Max 100100
#define pii pair<int, int>
using namespace std;

// Time Complexity O(ElogV) (E: edges and V: vertices)

//Algortimo para encontrar o menor caminho de um vértice de partida a todos outros do grafo.

//Algoritmo para grafo bidirecional a direcional 

int n, m; //número de vértices e arestas.
vector<pii>edges[Max]; //vector que representa o peso, primeiro elemento, e o vértice.
int dist[Max]; //vetor de distâncias mínimas.   
int vis[Max]; //vetor que tem como objetivo dizer se o vértice foi visitado ou não

void dijkstra(int s){ //começa no vértice s;

	for(int i=1; i<=n; i++) dist[i]=inf; //definimos todas as distâncias como infinito.
	dist[s]=0; //exceto o vértice que iremos começar.

	priority_queue<pii, vector<pii>, greater<pii>>queue; //Criamos uma fila de prioridade onde o menor fica no topo, em outras palavras, um min heap

	queue.push(make_pair(dist[s], s));

	while(true){
		int u=-1; //vértice que irá ser processado.	

		while(!queue.empty()){

			int a = queue.top().second; //a variável 'a' está pegando o vértice
			queue.pop();

			if(!vis[a]){
				u = a;
				break;
			}
		}

		if(u == -1) break; //não tem mais vértices para serem visitados, fim do algoritmo.
		vis[u] = true; //marcamos como visitado.


		// atualizar as distâncias
		for(int i=0; i < (int)edges[u].size(); i++){

			int v = edges[u][i].first; //distância do adjacente de u.
			int w = edges[u][i].second; //vértice do adjacente.

			//vendo se compensa atualizar a distância.
			if(dist[w] > dist[u]+v){
				dist[w] = dist[u]+v; //atualizando a distância.
				queue.push(make_pair(dist[w], w)); //inserimos na fila de prioridade. 
			}
		}
	}

}
 
