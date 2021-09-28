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


int main(){
  int n, q;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];
  cin >> q;
  vector<pii> b(q);
  rep(i, 0, q-1) {
    int buf; cin >> buf;
    b[i] = pii(buf, i);
  }

  sort(all(a));
  sort(all(b));

  vector<int> ans(q);
  int a_i = 0;
  for(auto be : b){
    int ret;
    if(be.first <= a[0]) ret = a[0] - be.first;
    else if(be.first >= a[n-1]) ret = be.first - a[n-1];
    else{
      while(a_i < n) {
        if(be.first > a[a_i]) a_i++;
        else break;
      }
      ret = min(be.first - a[a_i-1], a[a_i] - be.first);
    }
    ans[be.second] = ret;
  }

  for(auto v : ans) cout << v << endl;
}