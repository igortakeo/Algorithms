#include <bits/stdc++.h>
#define MAXN 50
#define MAX 4*MAXN+10
using namespace std;

/*
 * HLD - vertice
 * Segtree de minimo
 * 
 * Complexidades:
 * build - O(n)
 * query_path - O(log^2 (n))
 * update_path - O(log^2 (n))
 * query_subtree - O(log(n))
 * update_subtree - O(log(n))
 * 
 */

struct seg{

    int tree[4*MAX];
    int lazy[4*MAX];
    
    int query(int l, int r, int cn, int ra, int rb){
        if(lazy[cn]){ 
            tree[cn] += lazy[cn];    			  
            if(l != r){
                lazy[cn*2+1] += lazy[cn];                 
                lazy[cn*2+2] += lazy[cn];                 
            }
            lazy[cn] = 0;                                 
        }
        if(r < ra or l > rb) return MAX;                   
        else if(l >= ra and r <= rb) return tree[cn];
        int middle = (l+r)/2;
        return   min(query(l, middle, cn*2+1, ra, rb), query(middle+1, r, cn*2+2, ra, rb));
    }

    void updateValue(int l, int r, int a, int b, int new_value, int cn){
        if(lazy[cn]){ 
            tree[cn] += lazy[cn];    			  
            if(l != r){
                lazy[cn*2+1] += lazy[cn];                 	
                lazy[cn*2+2] += lazy[cn];                 	
            }
            lazy[cn] = 0;                                 	
        }
        if(l > b or r < a) return;
        else if(a <= l and r <= b){
            tree[cn] = new_value; 					
            if(l != r){
                lazy[cn*2+1] += new_value;                 
                lazy[cn*2+2] += new_value;                
            }
        }
        else{
            int middle = (l+r)/2;
            updateValue(l, middle, a, b, new_value, 2*cn+1);
            updateValue(middle+1, r, a, b, new_value, 2*cn+2);
            tree[cn] = min(tree[2*cn+1], tree[2*cn+2]);
        }
    }

    int build(int arr[], int l, int r, int cn){
        if(l == r){tree[cn] = arr[l]; return tree[cn];}
        int middle = (l+r)/2;
        int left = build(arr, l, middle, 2*cn+1);
        int right = build(arr, middle+1, r, 2*cn+2);
        return tree[cn] = min(left,right);
    }

    void init(){
        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);
    }


};



struct hld{
    vector<int>edges[MAXN];
    int pos[MAXN], sz[MAXN];
    int weight[MAXN], parent[MAXN];
    int head[MAXN], v[MAXN], n;
    seg stree;

    /*  Calculando o tamanho de cade vertice  
     *  e colocando o vertice mais pesado na 
     *  primeira posicao da lista de adjacencia.
     */
    void dfs(int i, int p = -1){
        sz[i] = 1;
        for(int &j : edges[i]){
            if(j != p){
                dfs(j, i);
                sz[i] += sz[j];
                if(sz[j] > sz[edges[i][0]] || edges[i][0] == p){
                    swap(j, edges[i][0]);
                }
            }
        }
    }  

    /* Constroi o vetor da segtree com os chains
     * o head de cada chain e o pai de cada  
     * vertice.
     */   
    void build_hld(int i, int p = -1){
        pos[i] = n;
        n++;
        v[pos[i]] = weight[i];
        for(int j : edges[i]){
            if(j != p){
                parent[j] = i;
                head[j] = (j == edges[i][0] ? head[i] : j);
                build_hld(j, i);
            }
        }
    }

    void build(int root){
        dfs(root);
        n = 0;
        head[root] = root;
        build_hld(root);
        stree.init();
        stree.build(v, 0, n-1, 0);
    }

    /* Realizando a query
     * vertice com menor peso entre 
     * o vertice a e b.
     */ 
    int query_path(int a, int b){
        if(pos[a] < pos[b]) swap(a, b);
        if(head[a] == head[b]) return stree.query(0, n-1, 0, pos[b], pos[a]);
        return min(stree.query(0, n-1, 0, pos[head[a]], pos[a]), query_path(parent[head[a]], b));
    }
    /* Atualizando um valor na arvore 
     */ 
    void update(int i, int newvalue){
        stree.updateValue(0, n-1, pos[i], pos[i], newvalue, 0);
    }

    /* Achando o LCA de dois vertices    
     */
    int lca(int a, int b){
        if(pos[a] < pos[b]) swap(a,b);
        return head[a] == head[b] ? b : lca(parent[head[a]], b);
    }
    /* Fazendo a atualizacao de um caminho inteiro.
     */ 
    void update_path(int a , int b, int x){
        if(pos[a] < pos[b]) swap(a, b);
        if(head[a] == head[b]){
            stree.updateValue(0, n-1, pos[b], pos[a], x, 0);
            return;
        }
        stree.updateValue(0, n-1, pos[head[a]], pos[a], x, 0);
        update_path(parent[a], b, x);
    }

    /*
     * Para realizar uma query na sub arvore de a. 
     */ 
    int query_subtree(int a){
        return stree.query(0, n-1, 0, pos[a], pos[a]+sz[a]-1);
    }
    /* 
     * Para realizar um update na sub arvore de a.
     */
    void update_subtree(int a, int x){
        stree.updateValue(0, n-1, pos[a], pos[a]+sz[a]-1, x, 0);        
    }

};

int main(){
    int m;
    cin >> m;
    hld tree;
    for(int i=0; i<m-1; i++){   
        int x, y;
        cin >> x >> y;
        x--; y--;
        tree.edges[x].push_back(y);
        tree.edges[y].push_back(x);
    }
    for(int i=0; i<m; i++){
        tree.weight[i]=i+1;
    }
    
    
    tree.build(0);
    
    //Testar as queries
    //Fazer a parte do update
    //...

    /*
    cout << tree.query_path(15, 17) << endl; // --> 2
    cout << tree.query_path(20, 19) << endl; // --> 14
    cout << tree.query_path(14, 16) << endl; // --> 7

    tree.update(13, 5);
    cout << tree.query_path(20, 19) << endl; // --> 5
    tree.update(18, 3);
    cout << tree.query_path(20, 19) << endl; // --> 3
    cout << tree.lca(15, 16) << endl; // --> 11
    
    tree.update_path(19, 20, 2);
    cout << tree.query_path(20,19) << endl;  // --> 2
    */

   
    return 0;
}
