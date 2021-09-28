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
  int n; cin >> n;
  string s, x;
  cin >> s >> x;

  vector<bool> dp(7);
  dp[0] = true; // Takahashi win

  int ten = 1;
  for(int i = n-1; i >= 0; i--) {
    vector<bool> old(7);
    swap(dp, old);
    rep(j, 0, 6) {
      int nj = (j + ten*(s[i]-'0')) % 7;
      if (x[i] == 'T') {
        dp[j] = old[j] | old[nj];
      } else {
        dp[j] = old[j] & old[nj];
      }
    }
    ten = (ten*10) % 7;
  }

  if (dp[0] == 1) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
}