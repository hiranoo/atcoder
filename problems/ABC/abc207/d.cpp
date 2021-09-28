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
const double EPS = 0.0001;

typedef struct POINT {
  double x, y;
} P;

double myabs(double a, double b){
  double d = a - b;
  if(d < 0) d = -d;
  return d;
}

P sg, tg;

void display(vector<P> &s){
  printf("#############\n");
  for(auto p : s){
    printf("(%lf, %lf)\n", p.x, p.y);
  }
  printf("\n");
}

void display2(vector<pair<double, double>> &s){
  printf("#############\n");
  for(auto p : s){
    printf("(%lf, %lf)\n", p.first/M_PI, sqrt(p.second));
  }
  printf("\n");
}

int main(){
  int n; cin >> n;
  vector<P> s(n), t(n);
  double gx, gy;
  gx = 0; gy = 0;
  rep(i, 0, n-1) {
    cin >> s[i].x >> s[i].y;
    gx += s[i].x;
    gy += s[i].y;
  }
  gx /= n; gy /= n; sg = P{gx, gy};

  gx = 0; gy = 0;
  rep(i, 0, n-1) {
    cin >> t[i].x >> t[i].y;
    gx += t[i].x;
    gy += t[i].y;
  }
  gx /= n; gy /= n; tg = P{gx, gy};

  
  // 重心中心に平行移動
  rep(i, 0, n-1){
    s[i] = P{s[i].x - sg.x, s[i].y - sg.y};
    t[i] = P{t[i].x - tg.x, t[i].y - tg.y};
  }
  
  display(s);
  display(t);

  // 角度ソート
  vector<pair<double, double>> ns(n), nt(n);
  rep(i, 0, n-1){
    double ang = atan2(s[i].y, s[i].x);
    double dis = s[i].x*s[i].x + s[i].y*s[i].y;
    ns[i] = make_pair(ang, dis);
  }
  rep(i, 0, n-1){
    double ang = atan2(t[i].y, t[i].x);
    double dis = t[i].x*t[i].x + t[i].y*t[i].y;
    nt[i] = make_pair(ang, dis);
  }

  display2(ns);
  display2(nt);

  sort(all(ns));
  sort(all(nt));

  cout << "###############" << endl;
  printf("atan2(%lf, %lf)=%lf [PI]\n\n", s[1].y, s[1].x, atan2(s[1].y, s[1].x));

  bool res = false;
  rep(i, 0, n-1){
    // ns[0] -> nt[i]
    double ang = nt[i].first - ns[0].first;
    bool ret = true;
    rep(j, 0, n-1){
      int k = (i+j) % n;
      // ns[j] -> nt[k]
      if(myabs(ns[j].second, nt[k].second) > EPS || myabs(nt[k].first - ns[j].first, ang) > EPS){
        ret = false;
        break;
      }
    }
    if(ret){
      res = true;
      break;
    }
  }
    
  if(res) cout << "Yes" << endl;
  else cout << "No" << endl;

}
