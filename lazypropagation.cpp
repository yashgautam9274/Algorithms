#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5+2;
const int INF = 1e18;
int a[N], tree[4*N], lazy[4*N];
 
void buildtree(int node, int st, int en){
    if(st==en){
        tree[node] = a[st];
        return;
    }
    int mid = (st + en)/2;
    buildtree(2*node,st,mid);
    buildtree(2*node+1,mid+1,en);
    tree[node] = (tree[node*2]+tree[node*2+1]);
}
 
int query(int node, int st, int en, int l, int r){

    if(lazy[node]!=0){
        int dx = lazy[node];
        lazy[node] = 0;
        tree[node] += (en-st+1)*(dx);
        if(st!=en){
            lazy[2*node] += dx;
            lazy[2*node+1] += dx;
        }
    }



    if(st>r || en<l){
        return 0;
    }
    if(l<=st && en<=r){
         return tree[node];
    }
    int mid = (st+en)/2;
    int q1 = query(2*node,st,mid,l,r);
    int q2 = query(2*node+1,mid+1,en,l,r);
    return (q1+q2);
}
 
void update(int node, int st, int en, int ll,int rr, int val){
    if(lazy[node]!=0){
        int dx = lazy[node];
        lazy[node] = 0;
        tree[node] += (en-st+1)*(dx);
        if(st!=en){
            lazy[2*node] += dx;
            lazy[2*node+1] += dx;
        }
    }
    if(st>rr || en<ll){
        return;
    }
    if(st>=ll && en<=rr){
        int dx = (en-st+1)*(val);
        tree[node] += (dx);
        if(st!=en){
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        return;
    }
    int mid = (st+en)/2;
    update(2*node,st,mid,ll,rr,val);
    update(2*node+1,mid+1,en,ll,rr,val);
    tree[node] = tree[2*node] + tree[2*node+1];
}


signed main(){
      int n,q;cin>>n>>q;
      for(int i=0;i<n;i++){
        cin>>a[i];
      }
      buildtree(1,0,n-1);
      int a,b,c,d;
      for(int i=0;i<q;i++){
        cin>>a;
        if(a==2){
            cin>>b;
            cout<<query(1,0,n-1,b-1,b-1)<<"\n";
        }
        else{
            cin>>b>>c>>d;
            update(1,0,n-1,b-1,c-1,d);
        }
      }
}