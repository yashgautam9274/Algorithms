//// also print the negative cycle  also;


#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int INF = 1e9;

signed main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> edges;
    vector<int> parent(n,-1);
    int u,v,w;
    for(int i=0;i<m;i++){
         cin>>u>>v>>w;
         edges.push_back({u,v,w});
    }
    int src;cin>>src;
    vector<int> dist(n,INF);
    dist[src] = 0;
    int x = -1;
    for(int i=0;i<n;i++){
        x = -1;
        for(auto e:edges){
            u = e[0];
            v = e[1];
            w = e[2];
            if(dist[v]>dist[u]+w){
                dist[v] = dist[u]+w;
                parent[v] = u;
                x = v;
            }
        }
    }
    if(x==-1){
        cout<<"No negative cycle found"<<"\n";
        return 0;
    }
    cout<<"Negative cycle found"<<"\n";
    for(int i=0;i<n;i++){
        x = parent[x];
        vector<int> cycle;
        for(int j=x;;j==parent[j]){
            cycle.push_back(j);
            if(j==x && cycle.size()>1){
                break;
            }
        }
        reverse(cycle.begin(),cycle.end());
        for(int it: cycle){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
}