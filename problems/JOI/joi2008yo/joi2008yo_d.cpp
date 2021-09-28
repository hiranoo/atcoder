#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#include <queue>
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
// typedef pair<ll, int> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;

struct P {
  int x, y;
  P() {
    x = 0; y = 0;
  }
  P(int xx, int yy) : x(xx), y(yy) {}
  bool operator< (const P &p) {
    if(x == p.x) return y < p.y;
    return x < p.x;
  }
  bool operator== (const P &p) {
    return x==p.x && y==p.y;
  }
  P operator+ (const P &p) {
    return P(x+p.x, y+p.y);
  }
  P operator- (const P &p) {
    return P(x-p.x, y-p.y);
  }
};

int main() {
  int n, m;
  cin >> m;
  vector<P> seiza(m);
  rep(i, 0, m-1) cin >> seiza[i].x >> seiza[i].y;
  cin >> n;
  vector<P> stars(n);
  rep(i, 0, n-1) cin >> stars[i].x >> stars[i].y;

  sort(all(seiza));
  sort(all(stars));
  
  P diff = P(0, 0);
  bool ok;
  rep(j, 0, n-1) {
    diff = stars[j] - seiza[0];
    // cout << "diff x:" << diff.x << " y: " << diff.y << endl;
    // diff = P(2, -3);
    ok = true;
    rep(k, 0, m-1) {
      // cout << "to x: " << (seiza[k]+diff).x << " y: " << (seiza[k]+diff).y << endl;
      if( !(seiza[k]+diff == stars[lower_bound(all(stars), seiza[k]+diff) - stars.begin()]) ) {
        ok = false;
        break;
      }
    }
    if(ok) break;
  }
  // rep(i, 0, m-1) {
  //   rep(j, 0, n-1) {
  //     diff = stars[j] - seiza[i];
  //     // cout << "diff x:" << diff.x << " y: " << diff.y << endl;
  //     // diff = P(2, -3);
  //     ok = true;
  //     rep(k, 0, m-1) {
  //       // cout << "to x: " << (seiza[k]+diff).x << " y: " << (seiza[k]+diff).y << endl;
  //       if( !(seiza[k]+diff == stars[lower_bound(all(stars), seiza[k]+diff) - stars.begin()]) ) {
  //         ok = false;
  //         break;
  //       }
  //     }
  //     if(ok) break;
  //   }
  // }
  // cout << ok << endl;
  cout << diff.x << " " << diff.y << endl;
}