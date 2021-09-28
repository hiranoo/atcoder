#include <bits/stdc++.h>
// #include <atcoder/segtree>
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

void chmin(ll &a, ll b) {
  if(a > b) a = b;
}

int main() {
  int n, m; cin >> n >> m;
  vector<vector<ll>> cost(n, vector<ll>(n, INF));
  vector<vector<ll>> time(n, vector<ll>(n, -1));
  rep(i, 0, m-1) {
    int s, t; ll d, ti;
    cin >> s >> t >> d >> ti;
    s--; t--;
    cost[s][t] = cost[t][s] = d;
    time[s][t] = time[t][s] = ti;
  }

  vector<vector<ll>> dp(1LL<<n, vector<ll>(n, INF));
  vector<vector<ll>> cas(1LL<<n, vector<ll>(n, INF));
  dp[0][0] = 0;
  cas[0][0] = 1;

  rep(s, 0, (1LL<<n)-1) rep(i, 0, n-1) rep(k, 0, n-1) {
    if(i == k) continue;
    if(s & (1LL<<i)) continue;
    if(dp[s][k] + cost[k][i] > time[k][i]) continue;
    // if(cost[k][i] > time[k][i]) continue;

    if(dp[s | 1LL<<i][i] > dp[s][k] + cost[k][i]){
      dp[s | 1LL<<i][i] = dp[s][k] + cost[k][i];
      cas[s | 1LL<<i][i] = cas[s][k];
    }else if(dp[s | 1LL<<i][i] == dp[s][k] + cost[k][i]) {
      cas[s | 1LL<<i][i] += cas[s][k];
    }
  }

  if(dp[(1LL<<n)-1][0] >= INF) cout << "IMPOSSIBLE" << endl;
  else cout << dp[(1LL<<n)-1][0] << " " << cas[(1LL<<n)-1][0] << endl;
}