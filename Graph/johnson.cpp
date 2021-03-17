#include <bits/stdc++.h>
#define MAX 1001
#define pb push_back
#define pii pair<int, int>
#define inf 0x3f3f3f3f 
using namespace std;

/*
    Find shortest paths between every pair of vertices
    in a given weighted directed graph and weights may 
    be NEGATIVE.

    Complexity: O((V^2)log(V) + VE)

    use Dijkstra and Bellman-Ford as subroutines.
*/


struct Edges{
	int x, y, weight;
};

vector<Edges>edges_bellford; 
vector<pii>edges[MAX]; 
int dist[MAX], vis[MAX], ans[MAX][MAX], parent[MAX]; 
int number_vertex, number_edges; 
map<pii, int>ed;

bool bellman_ford(int u){
    //u: source
    bool cycle_negative = false;

	for(int i=1; i<= number_vertex; i++) dist[i] = inf; 
	dist[u] = 0; 

	for(int i=0; i < number_vertex-1; i++){ 
		bool flag = false;
		for(auto v : edges_bellford){
			if(dist[v.x] != inf && dist[v.x]+ v.weight < dist[v.y]){ 
				dist[v.y] = dist[v.x] + v.weight;
				flag  = true;
			}	
		}
		if(!flag)break; 
	}
	
	for(auto v : edges_bellford){
		if(dist[v.x] != inf && dist[v.x]+ v.weight < dist[v.y]){
            cycle_negative = true;
            break;
        }		
	}	
	
    return cycle_negative;
}

void dijkstra(int s){
    // s: source

    memset(vis, 0, sizeof vis);
    memset(parent, -1, sizeof parent);

    vector<int> dist_dijkstra(number_vertex+1, inf);
	dist_dijkstra[s] = 0; 

	priority_queue<pii, vector<pii>, greater<pii>>queue; 

	queue.push(make_pair(dist_dijkstra[s], s));
	
	while(true){
		int u=-1; 	
		
		while(!queue.empty()){
			
			int a = queue.top().second; 
			queue.pop();	
			
			if(!vis[a]){
				u = a;
				break;
			}
		}
		
		if(u == -1) break; 
		vis[u] = 1; 
		
		
		for(int i=0; i < (int)edges[u].size(); i++){
			
			int v = edges[u][i].first; 
			int w = edges[u][i].second; 
			
			if(dist_dijkstra[w] > dist_dijkstra[u]+v){
				dist_dijkstra[w] = dist_dijkstra[u]+v;
                parent[w] = u; 
				queue.push(make_pair(dist_dijkstra[w], w));  
			}
		}
	}

}

int calc(int u, int v){
    if(u == v) return 0;
    if(parent[v] == -1) return inf;
    return ed[{parent[v], v}] + calc(u, parent[v]);
}

void jhonson(){

    for(int i=1; i<= number_vertex; i++){
        Edges p;
        p.x = 0;
        p.y = i;
        p.weight = 0;
        edges_bellford.pb(p);
    }

    bellman_ford(0);    

    for(Edges i : edges_bellford){
        if(i.x == 0) continue;
        int x = i.x;
        int y = i.y;
        edges[x].pb({i.weight+dist[x]-dist[y],y});
    }

    for(int i=1; i<=number_vertex; i++){
        dijkstra(i);
        for(int j=1; j<= number_vertex; j++){
            ans[i][j] = calc(i, j);
        }
    }

}

int main(){

    cin >> number_vertex >> number_edges;
    
    //transform to one based

    for(int i=0; i<number_edges; i++){
        int u, v, w;
        cin >> u >> v >> w;
        Edges p;
        p.x = u+1; 
        p.y = v+1;
        p.weight = w;
        ed[{p.x,p.y}] = p.weight;
        edges_bellford.pb(p);
    }

    jhonson();
    
    for(int i=1; i<=number_vertex; i++){
       for(int j=1; j<=number_vertex; j++){
            cout << i << ' ' << j << ": " << ans[i][j] << endl;
       }
    }    

    return 0;
}
