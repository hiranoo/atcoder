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
  vector<int> f(n);
  rep(i, 0, n-1){
    int buf; cin >> buf;
    if(i % 2 == 0) f[i] = (buf + 1)%2;
    else f[i] = buf;
  }

  vector<int> kogo(0);
  int cur_num = 0;
  int sum = 0;
  rep(i, 0, n-1){
    if(cur_num != f[i]){
      kogo.push_back(sum);
      cur_num = f[i];
      sum = 0;
    }
    sum++;
  }
  kogo.push_back(sum);

  int ans = 0;
  sum = 0;
  n = kogo.size();
  if(n < 3){
    rep(i, 0, n-1){
      sum += kogo[i];
    }
    cout << sum << endl;
    return 0;
  }

  rep(i, 0, n-3){
    sum = kogo[i] + kogo[i+1] + kogo[i+2];
    ans = max(ans, sum);
  }
  
  cout << ans << endl;
  
  //rep(i, 0, kogo.size()-1) cout << kogo[i] << endl;
}