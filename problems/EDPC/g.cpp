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
const int MAX_N = 100005;

vector<int> dp(MAX_N, -1);

int f(vector<vector<int>> &G, int x) {
  if(G[x].size() == 0) {
    dp[x] = 0;
    return 0;
  }
  
  if(dp[x] != -1) return dp[x];

  int ret = 0;
  for(auto nx : G[x]){
    ret = max(ret, f(G, nx) + 1);
  }

  dp[x] = ret;
  return ret;
}

int main() {
  int n,m; 
  cin >> n >> m;
  vector<vector<int>> G(n, vector<int>(0));
  rep(i, 0, m-1) {
    int x, y; cin >> x >> y; x--; y--;
    G[x].push_back(y);
  }

  rep(i, 0, n-1) {
    f(G, i);
  }

  int ans = 0;
  for(auto v : dp) ans = max(ans, v);
  cout << ans << endl;
}

/* O(n^2)なのでボツ
int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> G(n, vector<int>(0)), revG(n, vector<int>(0));
  rep(i, 0, m-1){
    int x, y; cin >> x >> y; x--; y--;
    G[x].push_back(y);
    revG[y].push_back(x);
  }

  vector<int> seed;
  for(int i = 0; i < n; i++) {
    if(G[i].size() == 0) seed.push_back(i);
  }

  // rep(i, 0, n-1) {
  //   cout << i << " : "; 
  //   for(auto v : revG[i]) cout << v << " ";
  //   cout << endl;
  // }

  // cout << "seed" << endl;
  // for(auto s : seed) cout << s << " "; cout << endl;

  int ans = 0;
  for(auto s : seed) {
    queue<pii> que;
    que.push(pii(s, 0));
    vector<int> used(n, false);
    while(que.size()){
      pii p = que.front(); que.pop();

      ans = max(ans, p.second);

      used[p.first] = true;

      for(auto v : revG[p.first]){
        //if(used[v]) continue;
        que.push(pii(v, p.second+1));
      }
    }
  }

  cout << ans << endl;
}
*/