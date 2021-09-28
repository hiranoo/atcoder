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
const int INF = 1001001001;

int main() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  int m = 1;
  rep(i, 0, n-2) {
    if(s[i] != s[i+1]) m++;
  }

  // cout << m << endl;

  int d = m;
  if(m == 1) d = 1;
  else{
    rep(i, 1, k) d -= 2;
    if(d < 2) d = 1;
  }

  cout << n - d << endl;
}