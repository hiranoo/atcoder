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
  int n, q; cin >> n >> q;
  int m = 200010;
  
  vector<int> a(n), b(n);
  vector<multiset<int>> s(m);
  multiset<int> maxs;

  auto getMax = [&] (int i) {
    if(s[i].size()) return *s[i].rbegin();
    return 0;
  };
  auto addYochien = [&] (int i) {
    int x = getMax(i);
    if(x > 0) maxs.insert(x);
  };
  auto delYochien = [&] (int i) {
    int x = getMax(i);
    if(x > 0) maxs.erase(maxs.find(x));
  };
  auto addEnji = [&] (int i, int r) {
    delYochien(i);
    s[i].insert(r);
    addYochien(i);
  };
  auto delEnji = [&] (int i, int r) {
    delYochien(i);
    s[i].erase(s[i].find(r));
    addYochien(i);
  };

  rep(i, 0, n-1) {
    cin >> a[i] >> b[i];
    addEnji(b[i], a[i]);
  }

  // rep(i, 0, m-1) if(s[i].size()) {
  //   for(auto v : s[i]) cout << v << " "; cout << endl;
  // }

  // for(auto v : maxs) cout << v << " "; cout << endl;

  while(q--) {
    int i, d; cin >> i >> d; i--;
    delEnji(b[i], a[i]);
    b[i] = d;
    addEnji(b[i], a[i]);
    cout << *maxs.begin() << endl;
  }
}