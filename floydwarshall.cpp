#include <bits/stdc++.h>
#define inf 0x3f3f3f3f //inf=1061109567
#define MAX 101
using namespace std;

int dp[MAX][MAX]; //tabela de caminhos minimos
int number_vertex; //numero de vertices
vector<int>edges[MAX]; //grafo
//Time Complexity : O(V^3)
//(V == number_vertex)

void floydWarshall(){//execucao do floyd warshall
	for(int k=1; k <= number_vertex; k++){//Testando todos os caminhos entre os vertices (v,w) e pegando o de menor peso 
		for(int v=1; v<= number_vertex; v++){
			for(int w=1; w <= number_vertex; w++) dp[v][w] = min(dp[v][k]+dp[k][w], dp[v][w]);
		}
	}
}

void constructTable(){
	
	/*
	 * Nesta parte sera construida a situacao
	 * inicial da tabela dp, de acordo com o 
	 * grafo recebido no input.
	 * 
	 */ 	  		 
}


