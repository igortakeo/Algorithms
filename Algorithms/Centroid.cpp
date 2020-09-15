#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define inf 0x3f3f3f3f 
#define MAX 1025
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

// Time Complexity O(nlogn)

vector<ll>tree[MAX];
vector<ll>centroidtree[MAX];
bool dead[MAX];
ll sz[MAX];
int nDead;
ll n;

void calc_size(ll u, ll ant = -1){
    sz[u] = 1;
    for(int i = 0; i < tree[u].size(); i++){
        if(tree[u][i] == ant or dead[tree[u][i]]) continue;
        calc_size(tree[u][i], u);
        sz[u] += sz[tree[u][i]];
    }
}

ll centroid(ll u, ll tot){

    for(int i=0; i<tree[u].size(); i++){
        if(sz[tree[u][i]] > sz[u] or dead[tree[u][i]]) continue;

        if(2*sz[tree[u][i]] > tot) return centroid(tree[u][i], tot);
    }

    return u;
}


ll centroid_decomp(ll root){

    //size of subtree if the node is rooted
    calc_size(root);

    //u will be he centroid
    ll u = centroid(root, sz[root]);
    dead[u] = true;

    cout << u << ' ';

    //build the centroid tree
    for(auto it : tree[u]){

        if(!dead[it]){

            int v = centroid_decomp(it);

            centroidtree[u].push_back(v);
            centroidtree[v].push_back(u);
        }
    }

    return u;
}



int main(){
	fastcin	
    
    ll m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    nDead = 0;
    centroid_decomp(1);

    cout << endl;

    return 0;
}
	
