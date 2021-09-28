
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

ll search(ll D, int n, int m, vector<ll> &d, vector<ll> &k){
  sort(all(d));
  sort(all(k));
  d.push_back(D); // n+1番目の店@Dとする

  int offset=0;
  ll ans = 0;
  rep(i, 0, m-1){
    ll vk = k[i];
    offset = lower_bound(d.begin()+offset, d.end(), vk) - d.begin();
    //cout << "offset:" << offset << " d-vk:" << d[offset]-vk << " vk-d:" << vk-d[offset-1] << endl;
    ll tmp = min(d[offset]-vk, vk-d[offset-1]); offset--;
    //cout << "tmp:" << tmp << endl;
    ans += tmp;
  }
  return ans;
}

int main(){
  ll D; int n, m;
  vector<ll> ans(10);
  int len = 0;
  while(1){
    cin >> D; // 1 cycle length
    if(D==0) break;
    cin >> n;
    cin >> m;
    vector<ll> d(n); d[0]=0;
    vector<ll> k(m);
    
    rep(i, 1, n-1) cin >> d[i];
    rep(i, 0, m-1) cin >> k[i];
    
    
    ans[len++] = search(D, n, m, d, k);
  }

  rep(i, 0, len-1) cout << ans[i] << endl;
}

