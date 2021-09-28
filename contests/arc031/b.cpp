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

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool judge(vector<string> &a, vector<vector<bool>> &v){
  rep(y, 0, 9){
    rep(x, 0, 9){
      if(!v[y][x] && a[y][x]=='o') return false;
    }
  }
  return true;
}

bool inside(vector<string> &a, vector<vector<bool>> &v, int x, int y){
  if(0<=x && x<10 && 0<=y && y<10 && !v[y][x] && a[y][x]=='o') return true;
  return false;
}

void search(vector<string> &a, vector<vector<bool>> &v, int x, int y){
  v[y][x] = true;

  rep(i, 0, 3){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(inside(a, v, nx, ny)) search(a, v, nx, ny);
  }
  
}


int main(){
  vector<string> area(10);
  rep(y, 0, 9) cin >> area[y];

  rep(y, 0, 9){
    rep(x, 0, 9){
      if(area[y][x] == 'o') continue;
      vector<vector<bool>> visited(10, vector<bool>(10, false));
      search(area, visited, x, y);
      if(judge(area, visited)){
        cout << "YES" << endl;
        return 0;
      }
    }
  }

  cout << "NO" << endl;
  return 0;
}