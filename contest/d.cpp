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
typedef long long ll;
using namespace std;
#define MAX_V 100
#define MAX_E 100
#define INF 100000
#define MAX_N 100005

typedef pair<int, int> Pii;

int main(){
  ll a, b, k; cin >> a >> b >> k;
  int n = a + b;
  string s="";
  rep(i, 0, a+b-1) s[i] = '?';

  vector<vector<int>> dp(a, vector<int>(b));

  rep(i, 0, a-1){
    rep(j, 0, b-1){
      if(i==0 || j==0) dp[i][j] = 1;
      dp[i][j] = (i+j+1)/(j+1) * dp[i][j-1];
    }
  }


   
  cout << s << endl;
  return 0;
}
