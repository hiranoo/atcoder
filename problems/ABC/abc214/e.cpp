#include <bits/stdc++.h>
#include <atcoder/segtree>
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
template<class T> inline bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<class T> inline bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1e9+7;
const ll INF = 1e18;

bool comp(const pii &a, const pii &b) {
  if(a.second == b.second) return a.first > b.first;
  return a.second < b.second;
}

void solve() {
  int n; cin >> n;
  vector<pii> a(n);
  rep(i, 0, n-1) cin >> a[i].first >> a[i].second;

  sort(all(a));
  priority_queue<int, vector<int>, greater<int>> q;
  int x = 1;
  for(auto v : a) {
    while(x < v.first && q.size()) {
      if(q.top() < x) {
        cout << "No" << endl;
        return;
      }
      q.pop();
      ++x;
    }
    x = v.first;
    q.push(v.second);
  }

  cout << "Yes" << endl;
}

int main() {
  int t; cin >> t;

  rep(_, 1, t) solve();  
}