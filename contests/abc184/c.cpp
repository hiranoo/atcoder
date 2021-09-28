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

bool same(pll a, pll b) {
  if(a.first == b.first && a.second == b.second) return true;
  return false;
}

bool once(pll a, pll b) {
  if(a.first + a.second == b.first + b.second) return true;
  if(a.first - a.second == b.first - b.second) return true;
  if(abs(a.first - b.first) + abs(a.second - b.second) <= 3) return true;
  return false;
}

bool twice(pll a, pll b) {
  if((a.first-b.first - a.second + b.second) % 2 == 0) return true;

  rep(dy, -3, 3) rep(dx, -3, 3) {
    if(abs(dy)+abs(dx) > 3) continue;
    pll c = pll(b.first+dy, b.second+dx);
    if(once(a, c)) return true;
  }
  return false;
}

int main() {
  pll s, g;
  cin >> s.first >> s.second >> g.first >> g.second;

  if(same(s, g)) cout << 0 << endl;
  else if(once(s, g)) cout << 1 << endl;
  else if(twice(s, g)) cout << 2 << endl;
  else cout << 3 << endl;
}