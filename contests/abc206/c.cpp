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

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  rep(i, 0, n-1) cin >> a[i];

  map<ll, int> group_value_size;
  rep(i, 0, n-1){
    if(group_value_size.count(a[i]) == 0) group_value_size[a[i]] = 1;
    else group_value_size[a[i]]++;
  }

  ll ans = 0;
  map<ll, int> memo;
  rep(i, 0, n-1){
    if(memo.count(a[i]) == 0) memo[a[i]] = 1;
    else memo[a[i]]++;
    ans += n - i - 1 - (group_value_size[a[i]] - memo[a[i]]);
  }

  cout << ans << endl;

  return 0;
}