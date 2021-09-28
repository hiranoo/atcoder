
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


double f(int a, int b, int c, int d, double x){
  return a*x*x*x + b*x*x + c*x + d;
}

pii square_solve(double a, double b, double c){
  double j = c - b*b/(4.0*a);
  //cout << "a:" << a << " b:" << b << " j:" << j << endl;

  if(b == 0) {
    if(a*c < 0) return pii(2, 0);
    else return pii(0, 0);
  }
  if(c == 0){
    if(a*b < 0) return pii(1, 0);
    else return pii(0, 1);
  }

  // a, b, c != 0
  // 重解
  if(fabs(j) <= 0.0001){
    if(a*b > 0) return pii(0, 2);
    if(a*b < 0) return pii(2, 0);
  }

  // 解なし
  if(a*j > 0) return pii(0, 0);

  // 異なる2個
  if(c*a > 0){
    if(-b*a > 0) return pii(2, 0);
    else return pii(0, 2);
  }
  else{
    return pii(1, 1);
  }

  return pii(100, 100);
}

pii solve(int a, int b, int c, int d){
  // ans
  pii ans = pii(0, 0);

  // x != 0
  if(d != 0){
    // 解を一つ求める
    double INF = 100000;
    double l = -INF, r = INF;
    double x;
    rep(i, 0, 1000){
      x = (l+r)/2.0;
      if(fabs(f(a, b, c, d, x)) <= 0.000001) break;
      if(f(a, b, c, d, x) > 0) r = x;
      else l = x;
    }
    if(x > 0) ans.first++;
    else ans.second++;

    //cout << "x:" << x << endl;
    pii res = square_solve(a, a*x+b, a*x*x+b*x+c);
    ans.first += res.first;
    ans.second += res.second;

  // x == 0
  }else{
    pii res = square_solve(a, b, c);
    ans.first += res.first;
    ans.second += res.second;
  }

  return ans;
}

int main(){
  int n, a, b, c, d;
  cin >> n;
  vector<pii> ans(n);
  rep(i, 0, n-1){
    cin >> a >> b >> c >> d;
    ans[i] = solve(a, b, c, d);
  }

  rep(i, 0, n-1){
    cout << ans[i].first << ' ' << ans[i].second << endl;
  }
}