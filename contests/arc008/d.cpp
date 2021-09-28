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

box op(box x, box y){
  return box(x.first*y.first, y.first*x.second+y.second);
}

box e(){
  return box(1, 0);
}

int main(){
  ll n; int m;
  cin >> n >> m;
  set<ll> p_body;
  vector<ll> p_input(m);
  map<ll, int> changed;
  map<ll, vector<box>> mp;
  rep(i, 0, m-1){
    ll p; double a, b; cin >> p >> a >> b;
    p_body.insert(p);
    p_input[i] = p;
    if(mp.count(p) == 0) mp[p] = vector<box>(0);
    mp[p].push_back(box(a, b));
  }

  segtree<box, op, e> seg(m);
  double min_ans = 10;
  double max_ans = -10;
  for(auto v : p_input){
    int machine_num = distance(p_body.begin(), p_body.find(v));
    //cout << "machine_num p:" << v << " order:" << machine_num << endl;
    seg.set(machine_num, mp[v][0]);
    mp[v].erase(mp[v].begin()); // 先頭はもう使ったので削除

    box ab = seg.all_prod();
    max_ans = max(max_ans, ab.first+ab.second);
    min_ans = min(min_ans, ab.first+ab.second);
  }

  cout << fixed << setprecision(8) << min_ans << endl;
  if(max_ans > 1) cout << fixed << setprecision(8) << max_ans << endl;
  else cout << 1 << endl;
}
