#include<bits/stdc++.h>
#define int long long


using namespace std;

int n,m;
const int N = 1e5 + 5;
const int INF = 1e18;
int cost = 0;
vector<pair<int,int>> adj[N];
vector<int> dist(N);
vector<bool> visited(n);

void prismmsp(int src){
    for(int i=0;i<n;i++){
        dist[i] = INF;
    }
    set<pair<int,int>> s;
    s.insert({0,src});
    dist[src] = 0;
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        int u = x.second;
        int w = x.first;
        visited[u] = true;
        cost += w;
        for(auto it : adj[u]){
            if(visited[it.first]){
                continue;
            }
            if(dist[it.first]>it.second){
                s.erase({dist[it.first],it.first});
                dist[it.first] = it.second;
                s.insert(dist[it.first],it.first);
            }
        }


    }
}

signed main(){
      cin>>n>>m;
      int u,v,w;
      for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
      }
}