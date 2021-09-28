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
  int n; cin >> n;
  vector<vector<int>> abc(n, vector<int>(3));
  rep(i, 0, n-1) cin >> abc[i][0] >> abc[i][1] >> abc[i][2];

  vector<vector<int>> dp(n+1, vector<int>(3, 0));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 3; j++) {
      for(int k = 0; k < 3; k++) {
        if(j == k) continue;
        dp[i+1][j] = max(dp[i+1][j], abc[i][j] + dp[i][k]);
      }
    }
  }

  cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
}