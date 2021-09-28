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
const ll INF = 1e16;

bool chmax(ll &a, ll b) {if(a < b) {a = b; return true;} return false;}
bool chmin(ll &a, ll b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int n, len; cin >> n >> len;
  int k; cin >> k;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];
  a.push_back(len);

  int ac = 0, wa = len;
  while(wa - ac > 1) {
    int wj = (ac + wa) / 2;
    auto f = [&](int d) {
      int pre = 0;
      int cnt = 0;
      rep(cur, 0, n) {
        if(a[cur] - pre < d) continue;
        pre = a[cur];
        cnt++;
      }
      if(cnt >= k+1) return true;
      else return false;
    };

    if(f(wj)) ac = wj;
    else wa = wj;
  }

  cout << ac << endl;
}