/*
#include <bits/stdc++.h>

//#include <atcoder/all>
typedef long long ll;
#define rep(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (ll i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (ll i = ((ll)(n)-1); i >= 0; --i)
#define rreps(i, n) for (ll i = ((ll)(n)); i > 0; --i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define repc2(i, s, n) for (ll i = (s); i <= (ll)(n); i++)
#define bitrep(i, n) for (ll i = 0, i##_len = (1ll << (ll)(n)); i < i##_len; i++)
#define bitrrep(i, n) for (ll i = (1ll << (ll)(n)) - 1ll; i >= 0; i--)
#define inf int(2e9)
#define linf 4000000000000000000ll
#define M7 1000000007ll
#define M09 1000000009ll
#define M9 998244353ll
#define all(v) begin(v), end(v)
using namespace std;
//using namespace atcoder;

ll n, d;
double dp[65][38][27][101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> d;
    ll f2 = 0, f3 = 0, f5 = 0, cd = d;
    while (cd % 2 == 0) cd /= 2, f2++;
    while (cd % 3 == 0) cd /= 3, f3++;
    while (cd % 5 == 0) cd /= 5, f5++;

    if (cd != 1) {
        puts("0");
        return 0;
    }
    dp[0][0][0][0] = 1;
    rep(p2, f2 + 1) rep(p3, f3 + 1) rep(p5, f5 + 1) rep(i, n) reps(d, 6) {
        ll n2 = p2, n3 = p3, n5 = p5;
        if (d == 2)
            n2 = min(f2, p2 + 1);
        if (d == 3)
            n3 = min(f3, p3 + 1);
        if (d == 4)
            n2 = min(f2, p2 + 2);
        if (d == 5)
            n5 = min(f5, p5 + 1);
        if (d == 6)
            n2 = min(f2, p2 + 1), n3 = min(f3, p3 + 1);
        dp[n2][n3][n5][i + 1] += dp[p2][p3][p5][i];
    }
    cout << fixed << setprecision(10);
    cout << dp[f2][f3][f5][n] / pow(6, n) << endl;
    return 0;
}
*/

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
using namespace std;
typedef long long ll;

int dp[61][39][27][101]; 

int main(){  
  ios_base::sync_with_stdio(false);
  ll n,d; cin >> n >> d;
  int f2=0; int f3=0; int f5=0;

  // 素因数分解
  // 2, 3, 5だけでいい
  ll tmp=d;
  //cout << 0 << endl;
  while(tmp >= 1){
    bool divided = false;
    if(tmp % 2==0){
      f2++;
      tmp /= 2;
      divided = true;
    }
    if(tmp % 3==0){
      f3++;
      tmp /= 3;
      divided = true;
    }
    if(tmp % 5==0){
      f5++;
      tmp /= 5;
      divided = true;
    }
    if(!divided) break;
  }

  // 7以上の素数が含まれるとき、確率0
  if(tmp > 5){
    cout << 7 << endl;
    return 1;
  }
  
  // D = 2**f2 * 3**f3 * 5**f5
  // Dのすべての約数についてi+1回以内で生成できる場合の数
  dp[0][0][0][0] = 1;

  rep(p2, 0, f2) rep(p3, 0, f3) rep(p5, 0, f5) rep(i, 0, n-1) rep(dice, 1, 6){
    ll n2=p2, n3=p3, n5=p5;
    if(dice==2) n2 = min(f2, p2+1);
    if(dice==3) n3 = min(f3, p3+1);
    if(dice==4) n2 = min(f2, p2+2);
    if(dice==5) n5 = min(f5, p5+1);
    if(dice==6){
      n2 = min(f2, p2+1);
      n3 = min(f3, p3+1);
    }
    dp[n2][n3][n5][i+1] += dp[p2][p3][p5][i];
  }

  //cout << fixed << setprecision(10);
  cout << dp[f2][f3][f5][n] / pow(6, n) << endl;
  
  return 0;
}
