#include <bits/stdc++.h>
#define MAXN 50
#define MAX 4*MAXN+10
#define pii pair<int, int>
#define ll long long
using namespace std;

/*
 * HLD - arestas
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
    //(j.first: vertice, j.second: peso da aresta que liga i e j.first)
    vector<pii>edges[MAXN];
    int pos[MAXN], sz[MAXN];
    int weight[MAXN], parent[MAXN];
    int head[MAXN], v[MAXN], n;
    seg stree;

    void dfs(int i, int p = -1){
        sz[i] = 1;
        for(auto &j : edges[i]){
            if(j.first != p){
                dfs(j.first, i);
                sz[i] += sz[j.first];
                if(sz[j.first] > sz[edges[i][0].first] || edges[i][0].first == p){
                    swap(j, edges[i][0]);
                }
            }
        }
    }  

    void build_hld(int i, int p = -1){
        pos[i] = n;
        n++;
        v[pos[i]] = weight[i];
        for(auto &j : edges[i]){
            if(j.first != p){
                weight[j.first] = j.second;
                parent[j.first] = i;
                head[j.first] = (j == edges[i][0] ? head[i] : j.first);
                build_hld(j.first, i);
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

    int query_path(int a, int b){
        if(pos[a] < pos[b]) swap(a, b);
        if(head[a] == head[b]) return stree.query(0, n-1, 0, pos[b]+1, pos[a]);
        return min(stree.query(0, n-1, 0, pos[head[a]], pos[a]), query_path(parent[head[a]], b));
    }

    void update(int i, int newvalue){
        stree.updateValue(0, n-1, pos[i], pos[i], newvalue, 0);
    }

    int lca(int a, int b){
        if(pos[a] < pos[b]) swap(a,b);
        return head[a] == head[b] ? b : lca(parent[head[a]], b);
    }

    void update_path(int a , int b, int x){
        if(pos[a] < pos[b]) swap(a, b);
        if(head[a] == head[b]){
            stree.updateValue(0, n-1, pos[b]+1, pos[a], x, 0);
            return;
        }
        stree.updateValue(0, n-1, pos[head[a]], pos[a], x, 0);
        update_path(parent[a], b, x);
    }

    int query_subtree(int a){
        if(sz[a] == 1) return 0;
        return stree.query(0, n-1, 0, pos[a]+1, pos[a]+sz[a]-1);
    }
    void update_subtree(int a, int x){
        if(sz[a] == 1) return;
        stree.updateValue(0, n-1, pos[a]+1, pos[a]+sz[a]-1, x, 0);        
    }

};

int main(){
   
    return 0;
}
