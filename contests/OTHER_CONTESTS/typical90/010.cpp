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
  int n; cin >> n;
  vector<pii> student(n);
  rep(i, 0, n-1){
    int c, p; cin >> c >> p;
    student[i] = pii(c, p);
  }

  int q; cin >> q;
  vector<pii> query(q);
  rep(i, 0, q-1) {
    int l, r; cin >> l >> r; query[i] = pii(l-1, r-1);
  }

  vector<ll> sum1(n, 0), sum2(n, 0);
  rep(i, 0, n-1){
    if(i != 0) {
      sum1[i] = sum1[i-1];
      sum2[i] = sum2[i-1];
    }
    if(student[i].first==1) sum1[i] += student[i].second;
    if(student[i].first==2) sum2[i] += student[i].second;
  }

  for(auto v : query){
    int l = v.first, r = v.second;
    if(l == 0) cout << sum1[r] << " " << sum2[r] << endl;
    else cout << sum1[r]-sum1[l-1] << " " << sum2[r] - sum2[l-1] << endl;
  }
} 