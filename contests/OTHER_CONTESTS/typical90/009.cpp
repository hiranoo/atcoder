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
#include <atcoder/modint>
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
using namespace atcoder;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;

struct P {
  int x, y;
  P(int _x=0, int _y=0) : x(_x), y(_y) {}
  bool operator== (const P &p){
    return x==p.x && y==p.y;
  }
  P operator- (const P &p){
    return P(x-p.x, y-p.y);
  }
  double angle(){
    return atan2(y, x)*180.0/M_PI;
  }
  ll norm(){
    return x*x+y*y;
  }
};


int main(){
  int n; cin >> n;
  vector<P> p(n);
  rep(i, 0, n-1){
    int x, y; cin >> x >> y;
    p[i] = P(x, y);
  }

  double res = 0;
  for(auto center : p){
    vector<mydouble> v;
    for(auto pp : p){
      if(pp == center) continue;
      mydouble ang = mydouble((pp-center).angle());
      v.push_back(ang);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    printf("center: (%d, %d)\n", center.x, center.y);
    for(auto vv : v){
      double opposite = vv + 180.0;
      if(opposite > 180) opposite -= 360;
      int l = lower_bound(all(v), opposite) - v.begin();
      int r = (l+1) % v.size();
      printf("vv: %lf, opposite: %lf, vl: %lf, vr %lf\n", vv, opposite, v[l], v[r]);

      //ret = max(ret, fabs(v[upper_bound(all(v), opposite)-v.begin()]-vv));
      //res = max(res, ret);
    }
  }

  cout << res << endl;
}