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

int main() {
  int k; cin >> k;
  map<int, int> queen;
  rep(i, 0, 7) queen[i] = -1;
  rep(i, 0, k-1) {
    int x, y; cin >> x >> y;
    queen[x] = y;
  }
  vector<int> idx(8);
  rep(i, 0, 7) idx[i] = i;

  map<int, int> ret;
  do {
    // for(auto i : idx) cout << i << " "; cout << endl;

    bool ok = true;
    ret = queen;

    rep(i, 0, 7) {
      if(ret[i] != -1 && ret[i] != idx[i]) {
        ok = false;
        break;
      }
      ret[i] = idx[i];
    }
    if(!ok) continue;

    bool atack = false;
    rep(i, 0, 7) {
      rep(j, 0, 7) {
        if(i == j) continue;
        if(abs(i-j) == abs(ret[i]-ret[j])) {
          atack = true;
          break;
        }
      }
    }
    if(!atack) break;
  } while(next_permutation(all(idx)));

  rep(i, 0, 7) {
    rep(j, 0, 7) {
      if(ret[i] == j) cout << "Q";
      else cout << ".";
    }cout << endl;
  }
} 