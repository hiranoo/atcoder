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

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> to(n, vector<int>(0));
  rep(i, 0, m-1) {
    int a, b; cin >> a >> b; a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  // bfs 頂点0からの最短距離を全頂点について求める
  queue<pii> que;
  que.push(pii(0, 0));
  vector<int> d(n, -1);
  while(que.size()) {
    pii p = que.front(); que.pop();
    int dep = p.first;
    int v = p.second;

    if(d[v] != -1) continue;
    d[v] = dep;

    for(auto nv : to[v]) {
      if(d[nv] != -1) continue;
      que.push(pii(dep+1, nv));
    }
  }

  vector<ll> num(n+1, 0);
  vector<bool> used(n, false);
  num[n] = 1; num[n-1] = 1;
  que.push(pii(n-1, n));
  while(que.size()) {
    pii p = que.front(); que.pop();
    int cur = p.first, pre = p.second;
    if(used[cur]) continue;
    for(auto par : to[cur]) {
      if(d[par] != d[cur]-1) continue;
      num[par] += num[cur];
      num[par] %= MOD;
      que.push(pii(par, cur));
    }
    used[cur] = true;
  }

  cout << (num[0] + MOD) % MOD << endl;
}