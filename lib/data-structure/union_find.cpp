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

int main(){
  UnionFind tree(8);
  tree.unit(0, 1);
  tree.unit(0, 5);
  tree.unit(6, 4);
  tree.unit(4, 7);
  tree.display();

  cout << " D" << tree.find(6) << endl;
}