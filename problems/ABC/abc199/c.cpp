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

void swap(string &a, int i, string &b, int j) {
  char tmp = a[i];
  a[i] = b[j];
  b[j] = tmp;
}

int main() {
  int n; cin >> n;
  string s; cin >> s;
  string a, b;
  rep(i, 0, n-1) a.push_back(s[i]);
  rep(i, 0, n-1) b.push_back(s[i+n]);

  int q; cin >> q;
  int cnt = 0;
  rep(_, 0, q-1) {
    int t, i, j; cin >> t >> i >> j; i--; j--;
    if(t == 1) {
      if(i < n && j < n) {
        if(cnt%2==0) swap(a, i, a, j);
        else swap(b, i, b, j);
      }
      if(i < n && n<= j) {
        if(cnt%2==0) swap(a, i, b, j-n);
        else swap(b, i, a, j-n);
      }
      if(n <= i) {
        if(cnt%2==0) swap(b, i-n, b, j-n);
        else swap(a, i-n, a, j-n);
      }
    }
    if(t == 2) cnt++;
  }
  if(cnt%2==0) cout << a+b << endl;
  else cout << b+a << endl;
}