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
typedef pair<int, int> pii;

int op(pii a, pii b){
  return pii(a.first*b.first, b.first*a.second+b.second);
}

int e(){
  return pii(1, 0);
}

int main(){
  int n, q; cin >> n >> q;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];
  segtree<pii, op, e> A(n);
  

  rep(i, 0, q-1){
    int t, x, v; cin >> t >> x >> v;
    if(t==1){
      
    }
  }

}