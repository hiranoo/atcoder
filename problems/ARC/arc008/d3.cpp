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
#include <atcoder/segtree>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
using namespace atcoder;
typedef pair<int, int> pii;

typedef pair<double, double> box;

struct Q{
  ll p; double a, b;
  bool operator< (const Q &q){
    return p < q.p;
  }
};

box op(box x, box y){
  return box(x.first*y.first, y.first*x.second+y.second);
}

box e(){
  return box(1, 0);
}

int main(){
  ll n; int m;
  cin >> n >> m;
  segtree<box, op, e> seg(m);
  vector<Q> queries(m);
  vector<pair<ll, int>> orders(m);
  rep(i, 0, m-1){
    ll p; double a, b;
    cin >> p >> a >> b;
    queries[i] = (Q){p, a, b};
    orders[i] = make_pair(p, i);
  }

  sort(all(orders));
  int index = -1;
  ll cur_p = -1;
  for(auto order : orders){
    ll p = order.first;
    int i = order.second;
    if(p != cur_p) {
      index++; cur_p = p;
    }
    queries[i].p = index;
  }

  /*
  for(auto query : queries){
    cout << "machine id: " << query.p << " a:" << query.a << " b:" << query.b << endl;
  }
  */

  double min_ans = 1e10;
  double max_ans = 1;
  for(auto query : queries){
    seg.set(query.p, box(query.a, query.b));
    box mul = seg.all_prod();
    double res = mul.first + mul.second;
    min_ans = fmin(min_ans, res);
    max_ans = fmax(max_ans, res);
  }

  cout << fixed << setprecision(10) << fmin(1, min_ans) << endl;
  cout << fixed << setprecision(10) << max_ans << endl;
}