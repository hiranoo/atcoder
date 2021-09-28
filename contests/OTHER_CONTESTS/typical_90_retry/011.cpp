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

struct Job {
  int d, c; ll s;
  // bool operator<(const Job &j) {
  //   if(d-c == j.d-j.c && d == j.d) return s > j.s;
  //   if(d - c == j.d - j.c) return d < j.d;
  //   return d-c < j.d-j.c;
  // }
  bool operator<(const Job &j) {
    if(d == j.d && c == j.c) return s > j.s;
    if(d == j.d) return c > j.c;
    return d < j.d;
  }
  bool operator==(const Job &j) {
    return d==j.d && c==j.c && s==j.s;
  }
};

int main() {
  int n; cin >> n;
  vector<Job> vec;
  rep(i, 0, n-1) {
    int d, c, s; cin >> d >> c >> s;
    vec.push_back((Job){d+1, c, (ll)s});
  }

  sort(all(vec));

  ll ans = 0;
  rep(s, 0, (1<<n)-1) {
    int fin = 1;
    bool ok = true;
    ll res = 0;
    rep(i, 0, n-1) if(s>>i & 1) {
      if(fin <= vec[i].d - vec[i].c) {
        fin += vec[i].c;
        res += vec[i].s;
      }else {
        ok = false;
        break;
      }
    }
    if(ok) ans = max(ans, res);
  }

  cout << ans << endl;
}