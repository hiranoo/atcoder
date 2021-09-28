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
const ll MOD = 1e9+7;

struct P {
  double ang;
  int x, y;
  bool operator< (const P &p) {
    if(fabs(ang - p.ang) < 0.0001) {
      return x*x+y*y > p.x*p.x+p.y*p.y;
    }else{
      return ang < p.ang;
    }
  }
  void show() {
    cout << "ang:" << ang << " x:" << x << " y:" << y << endl;
  }
};

struct POINT {
  int x, y;
  bool operator< (const POINT &p) {
    if(x == p.x) return y < p.y;
    return x < p.x;
  }
  bool operator== (const POINT &p) {
    return p.x==x && p.y==y;
  }
};

int area(P v1, P v2) {
  return abs(v1.x * v2.y - v2.x * v1.y);
}

int main() {
  int n; cin >> n;
  vector<int> x(n), y(n);
  vector<POINT> coord(n);
  rep(i, 0, n-1) cin >> x[i] >> y[i];
  rep(i, 0, n-1) coord[i] = (POINT){x[i], y[i]};
  if(n < 4) {
    cout << 0 << endl;
    return 0;
  }

  sort(all(coord));

  int ans = 0;
  rep(i, 0, n-1) rep(j, 0, i-1) {
    int x1 = coord[i].x, y1 = coord[i].y;
    int x2 = coord[j].x, y2 = coord[j].y;
    
    // cout << "1st: " << x1 << "--" << y1 << endl;
    // cout << "2nd: " << x2 << "--" << y2 << endl;
    // 3
    int a = lower_bound(all(coord), (POINT){x2+y1-y2, y2+x2-x1}) - coord.begin();
    // cout << "3rd: " << coord[a].x << "--" << coord[a].y << endl;
    if(!(coord[a] == (POINT){x2+y1-y2, y2+x2-x1})) continue;
    // 4
    a = lower_bound(all(coord), (POINT){x1+y1-y2, y1+x2-x1}) - coord.begin();
    // cout << "4th: " << coord[a].x << "--" << coord[a].y << endl;
    if(!(coord[a] == (POINT){x1+y1-y2, y1+x2-x1})) continue;
    ans = max(ans, (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
  }

  cout << ans << endl;
}