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
  string s; cin >> s;
  ll K; cin >> K;
  int x = 0, y = 0;

  auto clean = [&] () {
    set<pii> passed;
    passed.insert(pii(x, y));
    for(auto c : s) {
      if(c == 'R') passed.insert(pii(++x, y));
      if(c == 'L') passed.insert(pii(--x, y));
      if(c == 'U') passed.insert(pii(x, --y));
      if(c == 'D') passed.insert(pii(x, ++y));
    }
    return passed;
  };

  set<pii> first_set = clean();
  int cnt = 0;
  set<pii> tot = first_set;
  while(1) {
    set<pii> tmp = clean();
    bool ok = true;
    for(auto p : tmp) {
      tot.insert(p);
      if(first_set.count(p)) {
        ok = false; break;
      }
    }
    if(ok) break;
    if(first_set==tmp) break;
    cnt++;
  }

  if(cnt == 0) {
    cout << first_set.size() << endl;
    return 0;
  }
  set<pii> ss;
  x = 0, y = 0;
  int j = 0;
  while(j < cnt) {
    set<pii> tmp = clean();
    for(auto p : tmp) ss.insert(p);
    j++;
  }

  ll ans = (K/cnt) * ss.size();

  int left = K%cnt;
  set<pii> second;
  while(left--) {
    set<pii> tmp = clean();
    for(auto p : tmp) second.insert(p);
  }

  ans += second.size();
  cout << ans << endl;
}