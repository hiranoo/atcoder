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

vector< vector<ll> > dp(104, vector<ll>(104, INF));
vector< vector<pii> > c(104, vector<pii>(104, pii(-1, -1)));
vector<pii> m(104);

ll f(int i, int j) {
  if(i > j) return 0;
  if(dp[i][j] != INF) return dp[i][j];

  ll fans = INF;
  rep(k, i+1, j-1) {
    fans = min(fans, f(i, k) + f(k, j) + m[i].first * m[k].first * m[j-1].second);
  }
  return dp[i][j] = fans;
}

int main() {
  int n; cin >> n;
  
  rep(i, 0, n-1) cin >> m[i].first >> m[i].second;
  rep(i, 0, n-1) dp[i][i+1] = 0;

  cout << f(0, n) << endl;
}