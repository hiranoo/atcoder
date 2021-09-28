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

struct P {
  int a, b, c;
  P(){}
  P(int a, int b, int c) : a(a), b(b), c(c) {}
};

int main() {
  int n, m; cin >> n >> m;
  vector<ll> travel(m);
  rep(i, 0, m-1) cin >> travel[i];
  vector<P> train(n-1);
  rep(i, 0, n-2) cin >> train[i].a >> train[i].b >> train[i].c;

  vector<ll> sum(n, 0);
  rep(i, 0, m-2) {
    int u = travel[i]-1;
    int v = travel[i+1]-1;
    if(u > v) swap(u, v);
    sum[u]++;
    sum[v]--;
  }

  ll s = 0;
  ll ans = 0;
  rep(i, 0, n-2) {
    s += sum[i];
    // cout << s << " ";
    if(train[i].a * s > train[i].b * s + train[i].c) ans += train[i].b * s + train[i].c;
    else ans += train[i].a * s;
  }

  cout << ans << endl;
}