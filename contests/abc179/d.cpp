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
const ll MOD = 998244353;
const ll INF = 1e16;

bool chmax(ll &a, ll b) {if(a < b) {a = b; return true;} return false;}
bool chmin(ll &a, ll b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int n, k; cin >> n >> k;
  vector<pii> range(k);
  rep(i, 0, k-1) cin >> range[i].first >> range[i].second, range[i].second++;

  vector<ll> dp(n, 0);
  dp[0] = 1;
  vector<ll> sum(n, 0);
  // sum[0] = 1;

  rep(i, 0, n-1) {
    rep(j, 0, k-1) {
      if(i - range[j].first >= 0) dp[i] += sum[i - range[j].first];
      if(i - range[j].second >= 0) dp[i] -= sum[i - range[j].second];
      dp[i] %= MOD;
    }
    sum[i] += dp[i];
    if(i) sum[i] += sum[i-1];
    sum[i] %= MOD;
  }

  cout << (dp[n-1] + MOD) % MOD << endl;
}