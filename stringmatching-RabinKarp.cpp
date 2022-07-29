#include<bits/stdc++.h>

using namespace std;

int p = 31;
int const N = 1e5 + 7;
int const MOD = 1e9 + 7;
vector<int> powers(N);

int main(){
    string s,t;cin>>s>>t;
    int szs = s.length();
    int szt = t.length();
    powers[0] = 1;
    for(int i=1;i<N;i++){
        powers[i] = (powers[i-1]*p)%MOD;
    }
    cout<<"yes";
    vector<long long> t_hash(szt+1,0);
    for(int i=0;i<szt;i++){
         t_hash[i+1] = (t_hash[i] + (t[i]-'a' + 1)*powers[i])%MOD;
    }
    long long s_hash = 0;
    for(int i=0;i<szs;i++){
        s_hash = (s_hash + (s[i]-'a' + 1)*powers[i])%MOD;
    }
    int ans = 0;
    for(int i=0;i+szs-1<szt;i++){
        long long curh = (t_hash[i+szs] - t_hash[i] + MOD)%MOD;
        if(curh==(s_hash*powers[i])%MOD){
            ans++;
        }
    }
     cout<<ans<<"\n";
}