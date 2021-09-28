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
const ll MOD = 1e9+7;

bool cut(vector<int> &a, int x, int k, int n, int l){
  int idx = 0;
  int sum = 0;
  rep(c, 0, k-1){
    while(true){
      if(idx >= n) return false;
      if(a[idx]-sum >= x) break;
      idx++;
    }
    
    sum = a[idx];
  }
  if(l - a[idx] >= x) return true;
  return false;
}

int main(){
  int k, n, l;
  cin >> n >> l;
  cin >> k;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];

  int lb = 0, rb = l*2;
  while(rb - lb > 1){
    int x = (rb+lb)/2;
    if(cut(a, x, k, n, l)) lb = x;
    else rb = x;   
  }
  cout << lb << endl;
}