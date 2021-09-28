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
#include <atcoder/modint>
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
using namespace atcoder;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;

int encode(char c){
  switch(c){
    case 'a':
      return 1;
    case 't':
      return 2;
    case 'c':
      return 3;
    case 'o':
      return 4;
    case 'd':
      return 5;
    case 'e':
      return 6;
    case 'r':
      return 7;
  }
  return -1;
}

int main(){
  int n; string s;
  cin >> n;
  cin >> s;
  vector<int> a;
  for(auto c : s){
    if(c=='a' || c=='t' || c=='c' || c=='o' || c=='d' || c=='e' || c=='r') {
      int j = encode(c);
      if(j != -1) a.push_back(j);
    }
  }
  
  vector<int> dp(8, 0);
  for(auto v : a){
    if(v == 1) dp[1]++;
    else dp[v] += dp[v-1];
    dp[v] %= MOD;
  }

  cout << dp[7] << endl;
}