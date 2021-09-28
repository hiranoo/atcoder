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
  int n; cin >> n;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];
  sort(all(a));
  int q; cin >> q;
  rep(i, 0, q-1) {
    int b; cin >> b;
    int j = lower_bound(all(a), b) - a.begin();
    if(j == n) cout << b - a[n-1] << endl;
    else if(j > 0) cout << min(a[j]-b, b-a[j-1]) << endl;
    else cout << a[j]-b << endl;
  }
}