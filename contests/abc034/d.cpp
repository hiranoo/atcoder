
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

typedef pair<int, ll> nacl;

int main(){
  int n, k;
  cin >> n >> k;
  vector<nacl> a(n);
  rep(i, 0, n-1){
    ll w; int p;
    cin >> w >> p;
    a.at(i) = nacl(p, w);
  }
  sort(all(a));

  double l = 0, r = 101;
  rep(i, 0, 200){
    double x = (l+r)/2.0;
    vector<double> v(n);
    rep(j, 0, n-1){
      v[j] = (a[j].first - x) * a[j].second;
    }
    sort(all(v), greater<double>());
    double sum = 0;
    rep(j, 0, k-1) sum += v[j];
    if(sum >= 0) l = x;
    else r = x;
  }
  cout << fixed << setprecision(8) << l << endl;
}