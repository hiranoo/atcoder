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
  int n, m; cin >> n >> m;
  vector<int> f(n);
  rep(i, 0, n-1) cin >> f[i];

  vector<int> dp(n+1); // dp[i]: ある日に0 ~ i-1番目までを飲み終える方法の総数

  vector<int> counter(100005, 0), left(n+1);

  int l = 0;
  ll sum = 1;
  rep(r, 0, n-1){
    counter[f[r]]++;
    while(l < r && counter[f[r]] > 1){
      sum -= dp[l];
      counter[f[l]] --;
      l++;
    }
    dp[r] = sum;
    sum += dp[r];
  }

  dp[0] = 1;


  rep(i, 0, n-1) printf("dp[%d]= %d\n", i, dp[i]);
  cout << dp[n-1] << endl;
}