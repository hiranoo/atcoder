#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;

struct UnionFind {
  vector<int> par;
  int N;

  UnionFind(int n) : par(n) {
    N = n;
    for(int i = 0; i < n; i++){
      par[i] = i;
    }
  }
  
  int find(int x){
      if(par[x] == x) return x;
      return par[x] = find(par[x]);
  }

  void unit(int x, int y){
      x = find(x);
      y = find(y);
      if(x==y) return;
      par[x] = y;
  }

  bool same(int x, int y){
      return find(x) == find(y);
  }

  void display(){
    int used[N] = {0};
    for(int i = 0; i < N; i++){
      if(used[i]==1) continue;
      int p = i;
      if(p == par[p]){
        cout << p << endl;
        continue;
      }
      while(true){
        if(p == par[p]) break;
        cout << p << " -> ";
        used[p] = 1;
        p = par[p];
      }
    }
    cout << endl;
  }
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
  int h, w; cin >> h >> w;
  int q; cin >> q;
  UnionFind tree(h*w);
  vector<vector<bool>> red(h, vector<bool>(w, false));
  vector<bool> ans;

  rep(i, 0, q-1){
    int t; cin >> t;
    if(t == 1){
      int r, c; cin >> r >> c;
      r--; c--;
      red[r][c] = true;
      rep(j, 0, 3){
        int nx = c + dx[j];
        int ny = r + dy[j];
        if(0<=nx && nx<w && 0<=ny && ny<h){
          if(red[ny][nx]) tree.unit(r*w+c, ny*w+nx);
        }
      }
    }else {
      int x1, y1, x2, y2;
      cin >> y1 >> x1 >> y2 >> x2;
      y1--; x1--; y2--; x2--;
      ans.push_back(red[y1][x1] && red[y2][x2] && tree.same(y1*w+x1, y2*w+x2));
    }
  }
  
  for(auto a : ans){
    if(a) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}