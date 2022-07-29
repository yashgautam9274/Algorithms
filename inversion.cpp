#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 5;
int bit[N];

void update(int id, int val){
    while(id<=N){
        bit[id] += val;
        id += ((id) & (-id));
    }
}

int query(int id){
    int ans = 0;
    while(id>0){
        ans += bit[id];
        id -= ((id) & (-id));
    }
    return ans;
}


signed main(){
    int n;cin>>n;
    int ans[n];
    int x,ct;
    for(int i=0;i<n;i++){
          cin>>x;
          ct = query(N) - query(x);
          ans[i] = ct;
          update(x,1);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}