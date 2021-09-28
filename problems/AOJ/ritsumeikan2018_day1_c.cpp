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
  int n; cin >> n;
  vector<ll> a(n);
  rep(i, 0, n-1) cin >> a[i];

  vector<int> ans(0);
  map<ll, int> mp;
  rep(k, 0, n-1){
    if(mp.count(a[k]) == 0) mp[a[k]]=0;
    if(mp.count(a[n-1-k]) == 0) mp[a[n-1-k]]=0;
    mp[a[k]]++;
    mp[a[n-1-k]]--;
    if(mp[a[k]] == 0) mp.erase(a[k]);
    if(mp[a[n-1-k]] == 0) mp.erase(a[n-1-k]);

    if(mp.size() == 0) ans.push_back(k+1);
  }
  rep(i, 0, ans.size()-1){
    cout << ans[i];
    if(i != ans.size()-1) cout << " ";
    else cout << endl;
  }
}