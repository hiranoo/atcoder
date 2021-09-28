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
typedef pair<float, float> pff;
const ll MOD = 1e9+7;

struct K{
  int t, l, r;
};

bool no_overlap(K &a, K &b){
  if(a.t == 1) {
    if(b.t == 1) return a.r < b.l;
    if(b.t == 2) return a.r < b.l;
    if(b.t == 3) return a.r <= b.l;
    if(b.t == 4) return a.r <= b.l;
  }
  if(a.t == 2) {
    if(b.t == 1) return a.r <= b.l;
    if(b.t == 2) return a.r <= b.l;
    if(b.t == 3) return a.r <= b.l;
    if(b.t == 4) return a.r <= b.l;
  }
  if(a.t == 3) {
    if(b.t == 1) return a.r < b.l;
    if(b.t == 2) return a.r < b.l;
    if(b.t == 3) return a.r <= b.l;
    if(b.t == 4) return a.r <= b.l;
  }
  if(a.t == 4) {
    if(b.t == 1) return a.r <= b.l;
    if(b.t == 2) return a.r <= b.l;
    if(b.t == 3) return a.r <= b.l;
    if(b.t == 4) return a.r <= b.l;
  }
  return false;
}

int main(){
  int n; cin >> n;
  vector<K> lr(n);
  rep(i, 0, n-1){
    int t, l, r;
    cin >> t >> l >> r;
    lr[i] = (K){t, l, r};
  }

  int ans = 0;
  rep(i, 0, n-1){
    rep(j, i+1, n-1){
      if(no_overlap(lr[i], lr[j]) || no_overlap(lr[j], lr[i])) continue;
      ans++;
    }
  }

  cout << ans << endl;
}