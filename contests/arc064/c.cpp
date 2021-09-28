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
#define all(v) v.begin(), v.end()
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;


int main(){
  int n; ll x;
  cin >> n >> x;
  vector<ll> a(n);
  rep(i, 0, n-1) cin >> a[i];

  ll count = 0;
  rep(i, 0, n-2){
    ll sum = a[i] + a[i+1];
    if(sum <= x) continue;
    ll dif = sum - x;
    if(dif <= a[i+1]) a[i+1] -= dif;
    else{
      a[i+1] = 0;
      a[i] = x;
    }
    count += dif;
  }

  cout << count << endl;
}