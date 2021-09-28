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
  int h, w; 
  cin >> h >> w;
  vector<vector<char>> mp(h+2, vector<char>(w+2, '#'));

  rep(y, 0, h-1){
    string str; cin >> str;
    rep(x, 0, w-1){
      mp[y+1][x+1] = str[x];
    }
  }

  rep(y, 0, h+1){
    
    rep(x, 0, w+1){
      cout << mp[y][x];
    }cout << endl;
  }
  return 0;
}
