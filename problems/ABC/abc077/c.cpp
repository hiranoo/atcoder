
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
//#include <atcoder/segtree>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;


int main(){
  int n; cin >> n;
  vector<ll> a(n), b(n), c(n);

  rep(i, 0, n-1){ cin >> a[i]; }
  rep(i, 0, n-1){ cin >> b[i]; }
  rep(i, 0, n-1){ cin >> c[i]; }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  /*
  vector<ll> c_num(n, 0); // b[i]に対するc[j]の候補数j
  for(int i = 0; i < n; i++){
    if(b[i] >= c[n-1]) break;

    if(b[i] < c[0]) c_num[i] = n;
    else c_num[i] = c.end() - upper_bound(c.begin(), c.end(), b[i]);
  }
  //for(auto k : c_num) cout << " " << k; cout << endl;

  vector<ll> c_total(n, 0); // b[i],..., b[n-1]に対するc[j]の総和
  c_total[n-1] = c_num[n-1];
  for(int i = n-2; i >= 0; i--){
    c_total[i] = c_total[i+1] + c_num[i];
  }
  */

  vector<ll> c_total(n+1); c_total[n] = 0;
  for(int i = n-1; i >= 0; i--){
    if(b[i] >= c[n-1]) continue;

    if(b[i] < c[0]) c_total[i] = n + c_total[i+1];
    else{
      ll tmp = c.end() - upper_bound(c.begin(), c.end(), b[i]);
      //cout << " b[i]:" << b[i] << " tmp:" << tmp << endl;
      c_total[i] = tmp + c_total[i+1];
    }
  }

  //for(auto k : c_total) cout << " " << k; cout << endl;

  ll ans = 0;
  for(int i = 0; i < n; i++){
    if(a[i] >= b[n-1]) break;

    if(a[i] < b[0]) ans += c_total[0];
    else{
      int j = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
      ans += c_total[j];
    }
  }
  cout << ans << endl;
}