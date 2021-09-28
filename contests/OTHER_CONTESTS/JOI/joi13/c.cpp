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

  ll L = 0;
  rep(i, 0, n-1) {
    cin >> a[i];
    L += a[i];
  }

  // みんなの取り分が x以上であるか？
  ll l = -1, r = L;
  
  while(r - l > 1){
    ll x = (l+r)/2;
    //cout << "x:" << x << " l:" << l << " r:" << r << endl;
    bool c = false;

    int s = 0, t = 0;
    ll sum = 0;
    
    while(x <= L/3){
      while(sum < x && t < n+s){
        sum += a[t%n]; t++;
      }
      if(sum < x) break;
      while(1){
        if(s < n && sum-a[s] >= x){
          sum = sum - a[s++];
        }else{
          break;
        }
      }
      // @here sum = a[s]+ ... + a[t-1]
      //cout << "x:" << x << " pi 1) s:" << s << " t-1:" << t-1 << endl;
      if(s >= n) break;
      int s2 = t, t2 = t; ll sum2 = 0;
      while(sum2 < x && t2 < n+s){
        sum2 += a[t2%n]; t2++;
      }
      // @here sum2 = a[t]+ ... + a[t2-1]
      if(sum2 < x) break;
      //cout << "x:" << x << " pi 2) s2:" << s2 << " t2-1:" << t2-1 << endl;
      if(L - sum - sum2 >= x){
        c = true; break;
      }
      if(s >= n) break;
      sum -= a[s]; s++;
    }

    /*
    //cout << x << endl;
    // A[i]からとるとき
    rep(i, 0, n-1){
      //cout << " " << i << "番目から切り出す" << endl;
      int j = i; ll joi = 0;
      rep(k, 1, 2){
        //cout << "  " << k << "人目の分 最初にとるパイ:" << j%n << endl;
        joi = a[j%n]; j++;
        while(joi < x && j < n+i){
          joi += a[j%n]; j++;
        }
        //cout << "   最後に取ったパイ:" << (j-1)%n << " joi:" << joi << endl;
      }
      if(joi >= x){
        //cout << "ok\n" << endl;
         c = true;
         break;
      }//else cout << "ng\n" << endl;
    }
    */
    if(c) l = x;
    else r = x;
  }
    
  cout << l << endl;
}