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

vector<pii> factorize(int m){
  vector<pii> v;
  for(int i = 2; i*i <= m; i++){
    if(m % i != 0) continue;
    int idx = 0;
    while(m % i == 0){
      idx++;
      m /= i;
    }
    v.emplace_back(pii(i, idx));
  }
  if(m != 1) v.emplace_back(pii(m, 1));

  return v;
}

vector<int> div(int m){
  vector<int> v;
  v.emplace_back(1);
  for(int i = 2; i * i <= m; i++){
    if(m % i == 0){
      v.emplace_back(i);
      if(m/i != i) v.emplace_back(m/i);
    }
  }
  sort(all(v));
  return v;
}

int main(){
  int n, m; cin >> n >> m;

  vector<int> v = div(m);
  int d = distance(v.begin(), lower_bound(all(v), n));
  int ans;
  if(d < v.size()) ans = m / v[d];
  else ans = 1;
  cout << ans << endl;
}