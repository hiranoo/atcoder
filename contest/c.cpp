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
typedef long long ll;
using namespace std;
#define MAX_V 100
#define MAX_E 100
#define INF 100000
#define MAX_N 100005

typedef pair<int, int> Pii;

int main(){
  int n; cin >> n;
  vector<int> a(n+1), b(n+1), c(n+1), bb(n+10), aa(n+10);
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) cin >> b[i];
  rep(i, 1, n) cin >> c[i];
  rep(i, 0, n+5) {bb[i] = 0; aa[i] = 0;}

  // B[c[j]-1]
  rep(j, 1, n){
    bb[b[c[j]]]++;
  }

  long ans = 0;
  rep(i, 1, n){
    ans += bb[a[i]];
  }
  cout << ans << endl;

  /*
  // a[i]となる
  rep(i, 0, n-1){
    aa[a[i]]++;
  }

  int cnt = 0;
  rep(i, 1, n){
    cnt += aa[i]*bb[i];
  }
  //cout << cnt << endl;
  */
  return 0;
}