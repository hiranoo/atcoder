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

typedef struct CHOKOLATE{
  int z, x, y;
  bool operator< (const CHOKOLATE &c){
    return z > c.z;
  }
} choko;

bool too_many(vector<int> &a, int l){
  for(auto v : a){
    if(v > 0) l--;
  }
  return l < 0;
}

int main(){
  int n, m, p, q, r;
  cin >> n >> m >> p >> q >> r;
  vector<choko> c(r);
  rep(i, 0, r-1){
    int x, y, z; cin >> x >> y >> z;
    c[i] = (choko){z, x-1, y-1};
  }
  sort(all(c));

  for(auto v : c){
    //cout << "female: " << v.x << " male: " << v.y << " happiness: " << v.z << endl;
  }
  //cout << endl;
  ll ans = 0;
  for(ll s = 0; s < (1 << n); s++){
    if(bitset<20>(s).count() != p) continue;
    ll sum = 0;
    set<int> males;
    for(auto v : c){
      if(!(s & (1 << v.x))) continue;
      males.insert(v.y);
      if(males.size() > q){
        males.erase(v.y); continue;
      }
      sum += v.z;
    }
   
    ans = max(ans, sum);
  }

  cout << ans << endl;
}