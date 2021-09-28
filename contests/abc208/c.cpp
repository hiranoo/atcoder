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

int main(){
  int n; ll k;
  cin >> n >> k;
  vector<pii> a(n);
  rep(i, 0, n-1){
    int buf; cin >> buf;
    a[i] = pii(buf, i);
  }

  sort(all(a));

  ll base = k / n;
  ll left = k - base*n;
  vector<int> add(n, 0);
  for(int i = 0; i < left; i++){
    add[a[i].second]=1;
  }

  for(auto v : add){
    cout << base + v << endl;
  }
}