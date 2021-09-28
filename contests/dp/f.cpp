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

string chmax(string a, string b) {
  if(a.size() > b.size()) return a;
  else return b;
}

int main() {
  string s, t; cin >> s >> t;

  vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));

  rep(i, 1, s.size()) rep(j, 1, t.size()) {
    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    if(s[i-1] == t[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
  }

  int len = dp[s.size()][t.size()];

  int i = s.size();
  int j = t.size();

  string ans = "";
  while(len > 0) {
    // cout << i << " " << j << " " << len << endl;
    if(s[i-1] == t[j-1]) {
      ans.push_back(s[i-1]);
      i--;
      j--;
      len--;   
    }else if(dp[i][j] == dp[i-1][j]) {
      i--;
    }else{
      j--;
    }
    
  }
  reverse(all(ans));
  cout << ans << endl;

  // cout << "  i "; rep(i, 0, s.size()) cout << i << " "; cout << endl;
  // cout << "j     "; for(auto v : s) cout << v << " "; cout << endl;
  // rep(j, 0, t.size()) {
  //   if(j==0) cout << j << "   ";
  //   else cout << j%10 << " " << t[j-1] << " ";
  //   rep(i, 0, s.size()) {
  //     cout << dp[i][j] << " ";
  //   }cout << endl;
  // }
}