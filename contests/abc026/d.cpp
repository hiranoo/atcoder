
#include <iostream>
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
//#include <atcoder/segtree>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;

double f(int a, int b, int c, double t){
  double e = a*t + b*sin(c*M_PI*t) - 100;
  return e;
}

int main(){
  int a, b, c; cin >> a >> b >> c;

  double l = 0, r = 300;
  double t;
  rep(i, 0, 500){
    t = (l + r)/2.0;
    double e = f(a, b, c, t);
    if(fabs(e) <= 0.0000001) break;
    if(e > 0) r = t;
    else l = t;
  }

  cout << fixed << setprecision(10) << t << endl;
  return 0;
}
