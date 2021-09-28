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

const ll INF = 10000000000;

int main(){
  int n, q;
  cin >> n;
  vector<ll> a(n+2); a[0] = -INF; a[n+1] = INF;
  rep(i, 1, n) cin >> a[i];
  cin >> q;
  vector<int> b(q);
  rep(i, 0, q-1) cin >> b[i];

  sort(all(a));

  for(auto v : b){
    int r = upper_bound(all(a), v) - a.begin();
    cout << min(a[r]-v, v-a[r-1]) << endl;
  }
  
}