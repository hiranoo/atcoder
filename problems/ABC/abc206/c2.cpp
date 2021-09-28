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

/*
int main(){
  ll n; cin >> n;
  vector<ll> a(n);
  for(auto &v : a) cin >> v;

  ll ans = ((n * (n-1)) /2);
  sort(all(a));
  a.push_back(-1);
  int cnt = 1;
  rep(i, 0, n-1){
    if(a[i] != a[i+1]){
      ans -= ((cnt * (cnt-1))/2);
      cnt = 1;
    }else{ cnt++; }
  }
  cout << ans << endl;

  return 0;
}
*/

int main(){
  ll n;
  cin >> n;
  vector<long long> a(n);
  for(auto &nx : a){cin >> nx;}
  long long res1=(n*(n-1)/2);
  
  sort(a.begin(),a.end());
  a.push_back(-1);
  long long cnt=1;
  for(int i=0;i<n;i++){
    if(a[i]!=a[i+1]){
      res1-=((cnt*(cnt-1))/2);
      cnt=1;
    }
    else{cnt++;}
  }

  cout << res1 << endl;
}