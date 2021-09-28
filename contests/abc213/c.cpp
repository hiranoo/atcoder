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

int main() {
  int h, w, n; cin >> h >> w >> n;
  map<int, pii> mp;
  map<int, int> mpx, mpy;

  rep(i, 1, n) {
    int a,b; cin >> a >> b;
    mp[i] = pii(a, b);
    mpx[a]++;
    mpy[b]++;
  }

  int i = 1;
  for(auto itr = mpx.begin(); itr != mpx.end(); itr++) {
    itr->second = i++;
  }
  i = 1;
  for(auto itr = mpy.begin(); itr != mpy.end(); itr++) {
    itr->second = i++;
  }

  rep(i, 1, n) {
    pii p = mp[i];
    cout << mpx[p.first] << " " << mpy[p.second] << endl;
  }
  
}