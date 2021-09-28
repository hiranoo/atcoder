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

double dp[301][301][301];

double f(int n, int c1, int c2, int c3) {
  if(c1 < 0 || c2 < 0 || c3 < 0) return 0;
  double c = (double)(c1 + c2 + c3);
  if(c == 0) return dp[0][0][0] = 0;
  if(dp[c1][c2][c3] != -1) return dp[c1][c2][c3];

  return dp[c1][c2][c3] = n/c + c1/c*f(n, c1-1, c2, c3) + c2/c*f(n, c1+1, c2-1, c3) + c3/c*f(n, c1, c2+1, c3-1); 
}

int main(){
  int n; cin >> n;
  
  int c1=0, c2=0, c3=0;
  rep(i, 0, n-1){
    int buf; cin >> buf;
    if(buf == 1) c1++;
    if(buf == 2) c2++;
    if(buf == 3) c3++;
  }

  rep(i, 0, 300) rep(j, 0, 300) rep(k, 0, 300) dp[i][j][k] = -1;

  double ans = f(n, c1, c2, c3);
  cout << fixed << setprecision(10) << ans << endl;
}