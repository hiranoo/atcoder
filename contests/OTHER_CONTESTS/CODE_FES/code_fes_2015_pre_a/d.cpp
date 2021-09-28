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
  ll n; int m;
  cin >> n >> m;
  vector<ll> x(m+1), X(m+1); X[0] = 0; // 0番目を独自に定義する
  rep(i, 1, m) cin >> X[i];

  ll l = -1, r = n*2;
  while(r-l>1){
    ll t = (l+r)/2;
    x = X;
    bool c = true;
    //cout << "t:" << t << " l:" << l << " r:" << r << endl;
    
    rep(i, 1, m){
      ll ul = max(X[i-1], x[i-1]) + 1;
      if(x[i] > ul){
        if(x[i] - ul > t) c = false;
        else{
          ll left = x[i] - ul;
          x[i] = x[i] + max(t-2*left, (t-left)/2);
        }
      }else{
        x[i] = x[i] + t;
      }
      if(!c) break;
      //cout << " i:" << i  << " before:" << X[i] << " after:" << x[i] << endl;
    }
    if(c && x[m] >= n) r = t;
    else l = t;
    //cout << " after l:" << l << " r:" << r << endl;
  }

  cout << r << endl;
    
  return 0;    
}