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


int main() {
  int n; cin >> n;
  vector<int> a(n), b(n+5, 0);
  b[0] = 3;
  rep(i, 0, n-1) cin >> a[i];

  ll ans = 1;
  rep(i, 0, n-1) {
    ans = ans * b[a[i]] % MOD;
    b[a[i]]--;
    b[a[i]+1]++;
  }

  cout << (ans + MOD) % MOD << endl;

}