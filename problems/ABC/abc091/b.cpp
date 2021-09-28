#define _GLIBCXX_DEBUG
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
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;

int main(){
  int n, m;
  cin >> n;
  vector<string> s(n);
  rep(i, 0, n-1) cin >> s[i];
  cin >> m;
  vector<string> t(m);
  rep(i, 0, m-1) cin >> t[i];

  int ans = 0;
  rep(i, 0, n-1){
    int ret = 0;
    string str = s[i];
    rep(j, 0, n-1){
      if(str == s[j]) ret++;
    }
    rep(j, 0, m-1){
      if(str == t[j]) ret--;
    }
    ans = max(ret, ans);
  }

  cout << ans << endl;

  return 0;
}
