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
#include <atcoder/segtree>
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1e9+7;

pii search(vector<vector<int>> &G, int s, int n){
  stack<pii> stk; // node, depth
  stk.push(pii(s, 0));
  vector<bool> used(n, false);
  pii ans = pii(s, 0);
  while(stk.size()){
    pii p = stk.top(); stk.pop();

    if(ans.second <= p.second) ans = pii(p.first, p.second);
    
    for(auto v : G[p.first]){
      if(used[v]) continue;
      stk.push(pii(v, p.second+1));
      used[v] = true;
    }
  }

  //cout << s << " len=" << ans << endl;
  return ans;
} 

int main(){
  int n; cin >> n;
  vector<vector<int>> G(n, vector<int>(0));
  rep(i, 0, n-2){
    int a, b; cin >> a >> b; a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int s = 0; // 頂点0を基準にする
  pii v = search(G, s, n);
  int ans = search(G, v.first, n).second + 1;
  
  cout << ans << endl;
}