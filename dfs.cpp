
vector<int>vertices[N]; //lista de adjacências.
int vis[N] = {0}; //0 para não visitado e 1 para visitado.

void DFS(int x){ //x -> vértice inicial.
	vis[x] = 1;
	for(int i = 0; i < vertices[x].size(); i++){ //Vê se os vértices que estão ligados a x foram visitados. 
		int v = vertices[x][i]; 
		if(vis[v] == 0) DFS(v); //Se não, chama a recursão para esse vértice.
	}
}


vector<int>edges[N]; 

