
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
//#include <atcoder/segtree>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;


int main(){
  int n; cin >> n;
  vector<pair<ll, ll>> hs(n); // (h, s)
  rep(i, 0, n-1) cin >> hs[i].first >> hs[i].second;
  sort(all(hs));

  ll l = -1, r = pow(10, 15);
  while(r-l>1){
    bool c = true;
    ll x = (l+r)/2;
    vector<int> counter(n, 0);
    rep(i, 0, n-1){
      ll a = (x - hs[i].first) / hs[i].second; 
      
      // x < hs[i].firstでも、hs[i].secondが十分大きければ a=0となるため、aで判定シちゃダメ
      if(x < hs[i].first){
        c = false;
        break;
      }
      if(a < n) counter[a]++;
    }
    
    //cout << "x:" << x << " --counter" << endl;
    //rep(i, 0, n-1) cout << " " << counter[i]; cout << endl;

    int num = 0; // 割らないといけない風船の数 @t秒後
    rep(t, 0, n-1){
      num += counter[t];
      if(!c || num > t+1){
        c = false;
        break;
      }
    }

    if(c) r = x;
    else l = x;
  }

  cout << r << endl;
}
