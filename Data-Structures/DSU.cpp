#include <iostream>
#define MAXN 100100
using namespace std;

int n, k, pai[MAXN], peso[MAXN], qtd[MAXN];

int find(int x){
	if(pai[x] == x) return x;		
	return  pai[x]=find(pai[x]); //dp: guardando o pai de x.
} 

void join(int x, int y){
	
	x = find(x); //pegando o pai de x.
	y = find(y); //pegando o pai de y.		
	
	if(x==y) return; // se os dois tiverem o mesmo patriarca, quer dizer que ja estao unidos.

	//se um dos dois patriarcas tiver peso menor, faca o menor ser filho do maior.
	if(peso[x]<peso[y]){pai[x]=y; qtd[y]+=qtd[x];} 

	else if(peso[x]>peso[y]){pai[y]=x; qtd[x]+=qtd[y];}
	
	//se os dois tiverem  o mesmo peso, escolha um para ser pai de outro e aumente seu peso.
	else if(peso[x]==peso[y]){
		pai[x]=y;
		peso[y]++;
		qtd[y]+= qtd[x];
	}	
}
