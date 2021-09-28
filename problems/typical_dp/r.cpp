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
const ll INF = 1e18;

vector<int> dag_num;

void dfs(int v, vector<int> &tp, vector<vector<int>> &G, vector<bool> &used) {
  used[v] = true;
  for(auto u : G[v]) {
    if(!used[u]) dfs(u, tp, G, used);
  }
  tp.push_back(v);
}

void rdfs(int v, vector<vector<int>> &rG, vector<bool> &used, int k, vector<int> &cmp) {
  used[v] = true;
  cmp[v] = k;
  for(auto u : rG[v]) {
    if(!used[u]) rdfs(u, rG, used, k, cmp);
  }
}

vector<vector<int>> scc(vector<vector<int>> &G, vector<vector<int>> &rG) {
  int n = G.size();
  vector<bool> used(n, false);
  vector<int> tp;
  rep(i, 0, n-1) if(!used[i]) dfs(i, tp, G, used);

  rep(i, 0, n-1) used[i] = false;
  reverse(all(tp));
  vector<int> cmp(n);
  int k = 0;
  for(auto v : tp) if(!used[v]) {
    rdfs(v, rG, used, k++, cmp);
  }
  
  // dag
  vector<vector<int>> dag(k);
  rep(i, 0, n-1) {
    for(auto v : G[i]) {
      if(cmp[i] != cmp[v]) {
        dag[cmp[i]].push_back(v);
      }
    }
  }
  
  rep(i, 0, k-1) {
    sort(all(dag[i]));
    dag[i].erase(unique(all(dag[i])), dag[i].end());
  }

  rep(i, 0, k-1) {
    if(dag[i].size() == 0) dag[i].push_back(k);
  }

  // dag num
  dag_num.resize(k+1);
  rep(i, 0, k) dag_num[i] = 0;
  for(auto v : cmp) dag_num[v]++;

  return dag;
}

void display(vector<vector<int>> &G) {
  cout << "******************" << endl;
  int n = G.size();
  rep(i, 0, n-1) {
    for(auto v : G[i]) cout << v << " "; cout << endl;
  }

}

int main() {
  int n; cin >> n;
  vector<vector<int>> G(n), rG(n);
  rep(i, 0, n-1) rep(j, 0, n-1) {
    int a; cin >> a;
    if(a==1) {
      G[i].push_back(j);
      rG[j].push_back(i);
    }
  }

  // display(G);
  vector<vector<int>> dag = scc(G, rG);

  int m = dag.size();
  vector<vector<ll>> dp(m+1, vector<ll>(m+1, 0));
  rep(j, 0, m-1) rep(k, 0, m-1) for(auto i : dag[k]) {
    if(i > j) dp[i][j] = max(dp[i][j], dp[j][k] + dag_num[i]);
    if(i == j){
      if(*lower_bound(all(dag[j]), i) == i) dp[i][i] = max(dp[i][i], dp[j][k]+dag_num[i]);
    }
  }

  cout << dp[m][m] << endl;
}