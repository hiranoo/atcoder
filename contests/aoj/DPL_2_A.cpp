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
  vector< vector<ll> > cost(n, vector<ll>(n, INF));
  rep(i, 0, m-1) {
    int s, t, d; cin >> s >> t >> d;
    cost[s][t] = d;
  }

  vector< vector<ll> > dp(1LL<<n, vector<ll>(n, INF));
  dp[0][0] = 0;
  
  rep(s, 0, (1<<n)-1) rep(i, 0, n-1) rep(k, 0, n-1) {
    if(s & (1LL<<i)) continue;
    if(i == k) continue;
    // if(dp[s][k] + cost[k][i] < INF) cout << bitset<6>(s) << " " << k << "->" << i << " " << dp[s | (1LL<<i)][i] << ", " << dp[s][k] + cost[k][i] << " ";
    dp[s | (1LL<<i)][i] = min(dp[s | (1LL<<i)][i], dp[s][k] + cost[k][i]);
    // if(dp[s][k] + cost[k][i] < INF) cout << dp[s | (1LL<<i)][i] << endl;
  }

  // rep(s, 0, (1<<n)-1) rep(i, 0, n-1) if(dp[s][i] < INF) cout << bitset<6>(s) << " " << i << " " << dp[s][i] << endl;
  if(dp[(1<<n)-1][0] < INF) cout << dp[(1<<n)-1][0] << endl;
  else cout << -1 << endl;
}