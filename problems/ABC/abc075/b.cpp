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
typedef unsigned long long ll;
using namespace std;
#define INF 10000;

int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

int main(){
  int h, w;
  cin >> h >> w;
  int mp[h][w];
  rep(i, 0, h-1){
    string str; cin >> str;
    rep(j, 0, w-1){
      if(str[j] == '.') mp[i][j] = 0;
      else mp[i][j] = -INF;
    }
  }

  rep(y, 0, h-1) rep(x, 0, w-1){
    if(mp[y][x] >= 0) continue;
    rep(i, 0, 7){
      int yy = y + dy[i];
      int xx = x + dx[i];
      if(0 <= yy && yy <= h-1 && 0 <= xx && xx <= w-1) mp[yy][xx]++;
    }
  }

  rep(y, 0, h-1){
    rep(x, 0, w-1){
      if(mp[y][x] < 0) cout << '#';
      else cout << mp[y][x];
    }
    cout << endl;
  }
  
  return 0;
}