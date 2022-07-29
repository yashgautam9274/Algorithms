#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<int> indegree(n,0);
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> pq;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int x = pq.front();
        cout<<x<<" ";
        pq.pop();
        for(auto it : adj[x]){
             indegree[it]--;
             if(indegree[it]==0){
                pq.push(it);
             }
        }
    }
}