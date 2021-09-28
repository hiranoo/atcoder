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
//#include <bits/stdc++.h>
//#include <atcoder/segtree>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;
#define MAX_V 100
#define MAX_E 100
#define INF 100000
#define MAX_N 102

typedef struct Point{
  int x, y;
  bool operator < (const Point& p){
    return (x < p.x);
  }
} P;

int main(){
  int n; cin >> n;
  vector<P> r(n);
  vector<P> b(n);
  int cnt = 0;
  vector<bool> used(n); rep(i, 0, n-1) used[i]=false;

  rep(i, 0, n-1){
    int x, y; cin >> x >> y;
    r[i] = P{x, y};
  }
  rep(i, 0, n-1){
    int x, y; cin >> x >> y;
    b[i] = P{x, y};
  }

  sort(r.begin(), r.end());
  sort(b.begin(), b.end());

  //rep(i, 0, n-1) printf("red(%d, %d)\n", r[i].x, r[i].y);
  //rep(i, 0, n-1) printf("blue(%d, %d)\n", b[i].x, b[i].y);

  rep(i, 0, n-1){
    int argmax_j = -1;
    int max_y = -1;
    rep(j, 0, n-1){
      if(r[j].x >= b[i].x)break;
      if(used[j]) continue;
      if(max_y < r[j].y && r[j].y < b[i].y){
        argmax_j = j;
        max_y = r[j].y;
        //if(i == 2) printf("red(%d, %d)\n", r[j].x, r[j].y);
      }
    }
    //if(i == 2) printf("argmax_j:%d, max_y:%d\n", argmax_j, max_y);

    if(argmax_j != -1){
      used[argmax_j] = true;
      cnt++;
      //printf("i:%d red(%d, %d) < blue(%d, %d)\n", i, r[argmax_j].x, r[argmax_j].y, b[i].x, b[i].y);
    }
  }

  cout << cnt << endl;
  return 0;
}

