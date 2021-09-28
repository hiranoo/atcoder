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

ll div_five(ll n){
  ll idx = 0;
  for(ll i = 5; i <= n; i *= 5){
    if(n % i != 0) return idx;
    idx++;
  }
  return idx;
}

int main(){
  ll n; cin >> n;
  
  if(n % 2 != 0){
    cout << 0 << endl;
    return 0;
  }

  ll ans = 0;
  ll mul = 2 * 5;
  while(mul <= n){
    ans += n / mul;
    mul *= 5;
  }

  cout << ans << endl;
}