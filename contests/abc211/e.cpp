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

using vs = vector<string>;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, k; 
int ans;

void dfs(vs s) {
  int cnt = 0;
  rep(i, 0, n-1) rep(j, 0, n-1) if(s[i][j] == 'o') ++cnt;
  if(cnt == k) {
    ++ans;
    return;
  }
  rep(i, 0, n-1) rep(j, 0, n-1) {
    if(s[i][j] != '.') continue;
    if(cnt != 0) {
      bool ok = false;
      rep(v, 0, 3) {
        int ni = i + dx[v], nj = j + dy[v];
        if(ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
        if(s[ni][nj] == 'o') ok = true;
      }
      if(!ok) continue;
    }
    s[i][j] = 'o';
    dfs(s);
    s[i][j] = '#';
    dfs(s);
    return;
  }
}

int main() {
  cin >> n >> k;
  vs s(n);
  rep(i, 0, n-1) cin >> s[i];
  // dfs(s);  

  set<ull> que;
  rep(y, 0, n-1) rep(x, 0, n-1) if(s[y][x] == '.') que.insert(1ull << (y * n + x));

  rep(kk, 1, k) {
    set<ull> nxt;
    for(auto itr : que) {
      rep(y, 0, n-1) rep(x, 0, n-1) if(s[y][x] == '.' && !(*itr & (1ull << (y*n+x)))) {
        bool ok = false;
        rep(d, 0, 3) {
          int nx = x + dx[d], ny = y + dy[d];
          if(0<=nx && nx<n && 0<=ny && ny<n) {
            if(s[ny][nx] == '.' && (*itr & (1ull << (ny*n+nx))) {
              ok = true;
            }
          }
        }
        if(ok) nxt.insert(*itr | (1ull << y*n+x));
      }
    }
    swap(que, nxt);
  }
  
  cout << ans << endl;
}