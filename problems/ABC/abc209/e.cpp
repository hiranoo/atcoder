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

// -1: make, 0: draw, 1: kachi

int main(){
  int m; cin >> m;
  vector<pair<string, string>> dict(m);
  rep(i, 0, m-1) {
    string s; cin >> s;
    dict[i] = make_pair(s.substr(0, 3), s.substr(s.size()-3));
  }

  // 3文字に連続した番号を付ける
  map<string, int> mp;
  for(auto d : dict) {
    mp[d.first] = 0;
    mp[d.second] = 0;
  }
  int n = 0;
  for(auto &itr : mp) itr.second = n++;

  vector<vector<int>> G(n, vector<int>(0));
  vector<int> deg(n, 0);
  for(auto edge : dict) {
    int from = mp[edge.first];
    int to = mp[edge.second];
    G[to].push_back(from);
    deg[from]++;
  }

  queue<int> que;
  vector<int> res(n, 0);
  rep(i, 0, n-1) if(deg[i] == 0) {
    que.push(i);
    res[i] = -1;
  }
  
  while(que.size()) {
    int v = que.front(); que.pop();

    if(res[v] == -1) {
      for(auto u : G[v]) {
        if(res[u] != 0) continue;
        res[u] = 1;
        que.push(u);
      }
    }else if(res[v] == 1) {
      for(auto u : G[v]) {
        if(res[u] != 0) continue;
        deg[u]--;
        if(deg[u] == 0) {
          res[u] = -1;
          que.push(u);
        }
      }
    }
  }

  for(auto d : dict){
    int ans = res[mp[d.second]];
    if(ans == -1) cout << "Takahashi" << endl;
    if(ans == 0) cout << "Draw" << endl;
    if(ans == 1) cout << "Aoki" << endl;
  }

} 