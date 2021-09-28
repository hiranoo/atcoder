#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,cnt,MOD=1000000007,ans=1,bik[200001];
map<ll,ll> mp;
ll f(ll x,ll y){
    if(y==0)return 1;
    if(y%2==0)return f(x,y/2)*f(x,y/2)%MOD;
    return x*f(x,y-1)%MOD;
}
ll comb(ll x,ll y){
    return bik[x]*f(bik[x-y],MOD-2)%MOD*f(bik[y],MOD-2)%MOD;
}
int main(void){
    cin>>n>>m;
    bik[0]=1;
    for(ll i=1LL;i<=200000;i++){
        bik[i]=bik[i-1]*i%MOD;
    }
    
    for(ll i=2LL;i*i<=m;i++){
        cnt=0;
        while(m%i==0){
            mp[i]++;
            m/=i;
        }
    }
    if(m>1)mp[m]++;
    for(auto x:mp){
        //cout<<x.first<<" "<<x.second<<endl;
        ans*=comb(n-1+x.second,x.second)%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
}
