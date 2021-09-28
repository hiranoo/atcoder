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
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;
#define MAX_N 502

int W, H, N;
int X1[MAX_N], X2[MAX_N], Y1[MAX_N], Y2[MAX_N];

bool fld[MAX_N*6][MAX_N*6];

int compress(int *x1, int *x2, int w){
  vector<int> xs;

  rep(i, 0, N-1){
    rep(d, -1, 1){
      int tx1 = x1[i] + d;
      int tx2 = x2[i] + d;
      if(1 <= tx1 && tx1 <= w) xs.push_back(tx1);
      if(1 <= tx2 && tx2 <= w) xs.push_back(tx2);
    }
  }

  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());

  rep(i, 0, N-1){
    x1[i] = find(all(xs), x1[i]) - xs.begin();
    x2[i] = find(all(xs), x2[i]) - xs.begin();
  }

  return xs.size();
}

void solve(){
  W = compress(X1, X2, W);
  H = compress(Y1, Y2, H);

  memset(fld, 0, sizeof(fld));
  rep(i, 0, N-1){
    rep(y, Y1[i], Y2[i]){
      rep(x, X1[i], X2[i]){
        fld[y][x] = true;
      }
    }
  }

  cout << endl << "compressed field" << endl;
  rep(y, 0, H-1) {
    rep(x, 0, W-1){
      cout << (fld[y][x]? "b " : ". ");
    }cout << endl;
  }cout << endl;
  
}

int main(){
  cin >> W >> H >> N;
  rep(i, 0, N-1) cin >> X1[i];
  rep(i, 0, N-1) cin >> X2[i];
  rep(i, 0, N-1) cin >> Y1[i];
  rep(i, 0, N-1) cin >> Y2[i];

  solve();
}