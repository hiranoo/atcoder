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
// typedef pair<ll, int> P;
const ll MOD = 998244353;
const ll INF = 1e18;

struct P {
  int order, value, dir;
  bool operator< (const P &p) {
    return order < p.order; 
  }
};

int main(){
  int n, K; cin >> n >> K;

  vector<P> cs;
  rep(i, 1, K) {
    char c; int num;
    cin >> c >> num;
    if(c=='L') cs.push_back((P){num, i, 0});
    else cs.push_back((P){num, i, 1});
  }

  sort(all(cs));
  set<int> ss;
  vector<set<int>> cnt(n+1, set<int>(ss)); // cnt[0]は使わない
  vector<bool> fix(n+1, false);
  for(auto c : cs) {
    fix[c.order] = true;
    if(c.dir == 0){
      rep(i, 0, c.order-1) {
        cnt[i].insert(c.value);
      }
    }else{
      rep(i, c.order+1, n) {
        cnt[i].insert(c.value);
      }
    }
  }

  ll ans = 1;
  rep(i, 1, n) {
    if(fix[i]) continue;
    if(K > cnt[i].size()) ans *= K - cnt[i].size();
    else ans = 0;
    ans %= MOD;
  }
  cout << (ans + MOD) %MOD << endl;
}