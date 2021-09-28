#include <bits/stdc++.h>
#include <atcoder/all>
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
const ll INF = 1e16;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int K; cin >> K;
  
  if(K%9 > 0) {
    cout << 0 << endl;
    return 0;
  }

  vector<ll> dp(200005, 0);
  dp[0] = 1;

  rep(i, 0, K) {
    rep(j, 1, 9) dp[i+j] = (dp[i+j] + dp[i]) % MOD;
  }
  
  cout << (dp[K] + MOD) % MOD << endl;
}