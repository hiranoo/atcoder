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
const ll INF = 1e18;

struct S {
  ll x; int idx;
  S() {}
  S(ll x, int idx) : x(x), idx(idx) {}
};

S op(S a, S b) {
  if(a.x <= b.x) return a;
  return b;
}

S e() {
  return S(INF, 0);
}

int main(){
  int q; cin >> q;

  ll s = 0;
  priority_queue<ll, vector<ll>, greater<ll>> que;
  vector<ll> memo;
  rep(i, 0, q-1) {
    int t; ll x;
    cin >> t;
    if(t == 1) {
      cin >> x;
      que.push(x - s);
    }else if(t == 2) {
      cin >> x;
      s += x;
    }else {
      memo.push_back(que.top() + s);
      que.pop();
    }
  }

  for(auto v : memo) cout << v << endl;
}