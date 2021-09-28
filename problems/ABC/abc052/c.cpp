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

vector<pii> prime_factorize(int n){
  vector<pii> v(0);
  for(int i = 2; i * i <= n; i++){
    int idx = 0;
    while(n % i == 0){
      idx++;
      n /= i;
    }
    if(idx > 0) v.push_back(pii(i, idx));
  }
  if(n != 1) v.push_back(pii(n, 1));
  return v;
}

int main(){
  int n; cin >> n;

  if(n == 1){
    cout << 1 << endl;
    return 0;
  }

  vector<int> prime_counter(1001, 0);
  for(int i = 2; i <= n; i++){
    vector<pii> v = prime_factorize(i);
    // debug
    //cout << i << endl;
    //for(auto p : v) cout << " prime:" << p.first << " x " << p.second << endl;
    
    for(auto p : v){
      prime_counter[p.first] += p.second;
    }
  }

  ll ans = 1;
  for(int i = 2; i <= n; i++){
    //cout << i << " ** " << prime_counter[i] << endl;
    ans *= prime_counter[i]+1;
    ans %= (ll)(1e9+7);
  }

  cout << ans << endl;
}