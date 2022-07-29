#include<bits/stdc++.h>
#define int long long


using namespace std;

int const N = 1e5 + 5;

vector<int> adj[N];
vector<int> revadj[N];
int visited[N];
vector<int> order;


void dfs(int node){
    visited[node] = 1;
    for(int child : adj[node]){
        if(visited[child]==0){
            dfs(child);
        }
    }
    order.push_back(node);
}

void dfs1(int node){
    visited[node] = 1;
    for(int child : revadj[node]){
        if(visited[child]==0){
            dfs1(child);
        }
    }
}

signed main(){
    int n,m;cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        revadj[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            dfs(i);
        }
    }
    // for(int i=order.size()-1;i>=0;i--){
    //     cout<<order[i]<<" ";
    // }
    // cout<<"\n";
    int ct = 0; // no of scc in graph
    memset(visited,0,sizeof(visited));
    for(int i=order.size()-1;i>=0;i--){
        if(visited[order[i]]==0){
            ct++;
            dfs1(order[i]);
        }
    }

}