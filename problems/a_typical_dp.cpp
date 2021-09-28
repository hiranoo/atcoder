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
//#include <bits/stdc++.h>
//#include <atcoder/segtree>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;
#define MAX_N 10005

int main(){
  int n; cin >> n;
  vector<int> p(n);
  rep(i, 0, n-1) cin >> p[i];

  vector<int> dp(MAX_N);
  rep(i, 0, MAX_N-1) dp[i] = 0;

  rep(i, 0, n-1){
    vector<int> created(0);
    created.push_back(p[i]);
    rep(j, 0, MAX_N-1){
      if(dp[j]>0 && dp[j+p[i]] == 0) created.push_back(j+p[i]);
    }
    rep(j, 0, created.size()-1){
      dp[created[j]]=1;
    }
  }

  int cnt = 1; // 上記計算は0点を含んでいないから
  rep(i, 0, MAX_N-1){
    cnt += dp[i]>0? 1: 0;
  }

  cout << cnt << endl;
}