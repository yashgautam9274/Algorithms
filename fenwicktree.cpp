#include<bits/stdc++.h>
#define int long long


using namespace std;

const int N = 1e5+5;
int bit[N];
int n;


void update(int idx, int val){
    while(idx<=n){
        bit[idx] += val;
        idx += ((idx) & (-idx));
    }
}

int query(int idx){
    int ans = 0;
    while(idx>0){
        ans += bit[idx];
        idx -= ((idx) & (-idx));
    }
    return ans;
}


signed main(){
      ios_base::sync_with_stdio(false);
	  cin.tie(NULL);
      cin>>n;
      int x;
      for(int i=1;i<=n;i++){
        cin>>x;
        update(i,x);
      }
    //   for(int i=1;i<=n;i++){
    //     cout<<bit[i]<<" ";
    //   }
    //   cout<<"\n";
      int yo = query(4) - query(2);
      cout<<yo<<"\n";
}