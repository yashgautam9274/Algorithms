#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> adj[200005];
int const INF = 1e9;

int main(){
    int n,m;cin>>n>>m;
    int a,b,c;
    vector<int> dist(n,INF);
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    int src;cin>>src;
    dist[src] = 0;
    set<pair<int,int>> st;
    st.insert({0,src});
    while(!st.empty()){
        auto x = *(st.begin());
        st.erase(x);
        for(auto it:adj[x.second]){
             if(dist[it.first]>dist[x.second]+it.second){
                st.erase({dist[it.first],it.first});
                dist[it.first] = dist[x.second] + it.second;
                st.insert({dist[it.first],it.first});
             }
        }
    }
    // printing distance
    for(int i=0;i<n;i++){
        if(dist[i]==INF){
            cout<<-1<<" ";
        }
        else{
            cout<<dist[i]<<" ";
        }
    }
    cout<<"\n";
}