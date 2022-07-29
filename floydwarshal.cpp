#include<bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 1e9;

signed main(){
    // graph is directed
    int n,m;cin>>n>>m;
    int dist[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dist[i][j] = INF;
        }
    }
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        dist[a][b] = c;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

}