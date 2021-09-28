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


int f(vector<vector<int>> &G, vector<int> &memo, int v) {
  if(memo[v] != -1) return memo[v];
  if(G[v].size()==0) return memo[v]=0;

  int ret = 0;
  for(auto nv : G[v]) {
    ret = max(ret, f(G, memo, nv)+1);
  }

  return memo[v] = ret;
}
int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> G(n, vector<int>(0));
  rep(i, 0, m-1) {
    int x, y; cin >> x >> y; x--; y--;
    G[x].push_back(y);
  }

  int ans = 0;
  vector<int> memo(n, -1);
  
  rep(i, 0, n-1) {
    ans = max(ans, f(G, memo, i));
  }

  cout << ans << endl; 
}