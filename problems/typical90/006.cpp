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
using mint = modint1000000007;

pii op(pii a, pii b){
  if(a.first <= b.first) return a;
  return b;
}

pii e(){
  return pii(100, -1);
}

int main(){
  int n, k;
  cin >> n >> k;
  string s; cin >> s;
  segtree<pii, op, e> seg(n);
  rep(i, 0, n-1) {
    seg.set(i, pii(s[i]-'a', i));
  }

  int head = -1;
  string ans = "";
  for(int tail = n-k; tail < n; tail++){
    pii cur = seg.prod(head+1, tail+1);
    head = cur.second;
    ans.push_back(s[head]);
  }

  cout << ans << endl;
}