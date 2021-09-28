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

int main(){
  ll p; cin >> p;

  vector<ll> value(11);
  value[0] = 1;
  rep(i, 1, 10) value[i] = value[i-1] * i;

  ll cnt = 0;
  for(int i = 10; i >= 1; i--){
    ll v = value[i];
    for(int c=1; c<=100; c++){
      if(p >= v) {
        p -= v;
        cnt++;
      }
    }
  }

  cout << cnt << endl;

}