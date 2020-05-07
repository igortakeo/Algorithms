#include <bits/stdc++.h>
#define Max 100100
#define pii pair<int, int>
using namespace std;
/*
	Algoritmo  de Fleury - encontrar um ciclo euleriano
	@author igortakeo
*/
vector<int>edges[Max];
bool visited[Max];
int graus[Max]={0};
int n, m, ft=0, first;

/*
	Adiciona a aresta removida temporiaramente.
*/

void add(int v, int u, pii l){
	edges[v][l.first] = u;
	edges[u][l.second] = v;
}

/*
	A funcao remove temporiaramente uma aresta,
	retornando as posicoes dos vertices "removidos"
	na lista de adjacencia.
	
*/
pii rmvMenosUm(int v, int u){
	int pos_1=0, pos_2=0;
	for(int i=0; i<edges[v].size(); i++){
		if(edges[v][i] == u){
			edges[v][i] = -1;
			pos_1=i;
			break;
		}
	}
	
	for(int i=0; i<edges[u].size(); i++){
		if(edges[u][i] == v){
			edges[u][i] = -1;
			pos_2=i;
			break;
		}
	}	
	return pii(pos_1, pos_2);
}

/*
	A funcao removeEdge remove uma aresta
*/

void removeEdge(int v, int u){
	int pos=0;
	for(int i=0; i<edges[v].size(); i++){
		if(edges[v][i] == u){
			pos=i;
			break;
		}
	}
	edges[v].erase(edges[v].begin()+pos);
	
	for(int i=0; i<edges[u].size(); i++){
		if(edges[u][i] == v){
			pos=i;
			break;
		}
	}
	edges[u].erase(edges[u].begin()+pos);
	
}
/*
	Uma dfs comum que retorna o numero de vertices
	que a funcao percorreu.
*/
int dfs(int v){
	
	visited[v]=true;  
	int cnt=1;
	
	for(int i=0; i<edges[v].size(); i++){
		int u = edges[v][i];
		if(!visited[u] && u!=-1) cnt+= dfs(u);
	}
	return cnt;
}
/*
	
	A funcao validEdge analisa se a aresta passada
	por parametro eh uma ponte.
*/

bool validEdge(int v, int u){
	
	if(edges[v].size() == 1) return true;
	
	memset(visited, false, sizeof visited);
	int cnt_1 = dfs(v);
	
	pii l = rmvMenosUm(v, u);
	memset(visited, false, sizeof visited);
	int cnt_2 = dfs(v);
	
	add(v, u, l);
	
	return (cnt_1 > cnt_2 || first==u)? false: true;				
	
}

/*
	A funcao cycleEuler executa uma dfs
	entrando no if apenas se aresta(v,l)
	nao for uma ponte.  
*/

void cycleEuler(int v){
	
	for(int i=0; i<	edges[v].size(); i++){
		int l = edges[v][i];

		if(validEdge(v,l)){
			cout << l  << ' ';
			removeEdge(v, l);	
			if(l == first) return;
			cycleEuler(l);
		}	
	}		
}


int main(){
	
	cin >> n >> m;
	
	int x, y;
	/*
		Cria o grafo com lista de adjacencia e 
		calula o grau de cada vertice.
	*/
	for(int i=0; i<n; i++){
		cin >> x >> y;
		edges[y].push_back(x);
		edges[x].push_back(y);
		graus[x]++;
		graus[y]++;
	}

	/*
		Vendo se existe grau impar 
	*/
	bool flag=true;
	for(int i=1; i<=m; i++){
		if(graus[i]%2!=0){
			flag=false;
			break;
		}
	}
	/*
		Se no grafo conter apenas dois vertices com grau impar
		ou todos os vertices pares, existe ciclo euleriano. 
	*/
	if(flag) {
		first = 1;
		cout << 1 << ' ';
		cycleEuler(1);
	}
	else cout << "Nao existe ciclo euleriano";
	
	cout << endl;
	
	return 0;
}
