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
const int INF = 1001001001;

// struct P {
//   int u, pre, cycle;
//   P(){}
//   P(int u, int pre, int cycle) : u(u), pre(pre), cycle(cycle) {}
//   void show() {
//     printf("u: %d, pre: %d, cycle: %d\n", u, pre, cycle);
//   }
// };

// P f(int turn, int u) {
//   if(visited[u].size() > 0) {
//     for(auto itr : visited[u]) {
//       if(turn%2 == itr%2) {
//         int pre = itr;
//         int cycle = turn - itr;
//         return P(u, pre, cycle);
//       }
//     }
//   }
//   visited[u].insert(turn);
  
//   if(turn%2 == 0) {
//     int v = to[0][u];
//     if(v == -1) return P(u, turn, 0);
//     return f(turn+1, v);
//   }else{
//     int v = to[1][u];
//     if(v == -1) return P(u, turn, 0);
//     return f(turn+1, v);
//   }
// }

// int pos(int c, int u, int cycle, int turn) {
//   vector<int> v; v.push_back(u);
//   int mi = x[u], ma = x[u];
//   rep(i, 1, cycle-1) {
//     if(turn%2 == 0) {
//       v.push_back(to[0][u]);
//       mi = min(mi, x[to[0][u]]);
//       if(mi < ma) return ma;
//     }else{
//       v.push_back(to[1][u]);
//       ma = max(ma, x[to[1][u]]);
//       if(mi < ma) return mi;
//     }
//     turn++;
//   }

//   return ma;
// }

int n, m; 
vector<int> x(100005);
vector<vector<int>> to(2, vector<int>(100005, -1));
vector<set<int>> visited(100005); // visited turn

bool f(int v, int turn, int id) {
  if(turn > 4*n) return false;
  if(id == -1) return false;
  if(turn%2==0 && x[id] >= v) return true;
  if(turn%2==1 && x[id] < v) return false;
  return f(v, turn+1, to[turn%2][id]);
}

int main() {
  cin >> n >> m;
  vector<vector<int>> G(n);
  rep(i, 0, n-1) cin >> x[i];
  rep(i, 0, m-1) {
    int a, b; cin >> a >> b; a--; b--;
    G[a].push_back(b);
  }

  rep(u, 0, n-1) {
    int mi = x[u], ma = x[u];
    int mi_u = u, ma_u = u;
    for(auto v : G[u]) {
      if(mi > x[v]) {
        mi = x[v];
        mi_u = v;
      }
      if(ma < x[v]) {
        ma = x[v];
        ma_u = v;
      }
    }
    if(ma_u != u) to[0][u] = ma_u;
    if(mi_u != u) to[1][u] = mi_u;
  }
  
  int l = -1, r = INF;
  while(r-l > 1) {
    int v = (l+r)/2;
    if(f(v, 0, 0)) l = v;
    else r = v;
  }

  cout << l << endl;
}