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
using namespace std;
#define MAX_V 100
#define MAX_E 100
#define INF 100000
#define MAX_N 100005


int main(){
  string s, t;
  cin >> s;
  cin >> t;

  int ns = s.length();
  int nt = t.length();

  int point = -1;

  rep(i, 0, ns-1){
    if(t[0] == s[i] || s[i] == '?'){
      //cout << "i:" << i << " s[i]:" << s[i] << endl;
      bool comp = true;
      rep(k, 1, nt-1){
        //cout << " k:" << k << endl;
        if(i+k >= ns){
          comp = false;
          break;
        }
        if(!(t[k] == s[i+k] || s[i+k] == '?')) {
          comp = false;          
          break;
        }
      }
      //cout << " comp:" << comp << endl;
      if(comp) point=i;
    }
  }

  if(point == -1) cout << "UNRESTORABLE" << endl;
  else{
    rep(i, 0, nt-1){
      s[point+i] = t[i];
    }
    rep(i, 0, ns-1){
      if(s[i]=='?') s[i] = 'a';
    }
    cout << s << endl;
  }

}