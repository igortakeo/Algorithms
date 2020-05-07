#include <bits/stdc++.h>
using namespace std;

//Problema da Mochila resolvido com DP

// defino os maiores valores de n e s como 1010
#define MAXN 1010
#define MAXS 1010

// declaro as variáveis que a função utiliza
int n, valor[MAXN], peso[MAXN], dp[MAXN][MAXS]

int knapsack(int obj, int aguenta){
	
	// se já calculamos esse estado da dp, retornamos o resultado salvo
	if(dp[obj][aguenta]>=0) return dp[obj][aguenta];
	
	// se não houver mais objetos ou espaço na mochila, retorno 0, pois não posso mais botar nada
	if(obj==n or !aguenta) return dp[obj][aguenta]=0;
	
	// teste para o caso em que nao se coloca o objeto(retorna o melhor caso possivel)
	int nao_coloca=knapsack(obj+1, aguenta);
	
	// se for possível colocar o objeto
	if(peso[obj]<=aguenta){
		//teste para o caso em que se coloca o objeto(retorna o melhor caso possivel) 
		int coloca=valor[obj]+knapsack(obj+1, aguenta-peso[obj]);
		
		// e a função deve retornar o melhor entre colocar ou não colocar
		return dp[obj][aguenta]=max(coloca, nao_coloca);
	}
	
	// se a função não retornou ainda, então ela não entrou no if
	// logo não era possível colocar o objeto 
	return dp[obj][aguenta]=nao_coloca; // então retorno o valor de não colocá-lo
}
