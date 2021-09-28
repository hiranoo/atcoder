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
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;

int compress(vector<int> &x1, vector<int> &x2, int w, int n){
  vector<int> xs(0);

  rep(i, 0, n-1){
    rep(d, -1, 1){
      int tx1 = x1[i] + d;
      int tx2 = x2[i] + d;
      if(0<=tx1 && tx1<w) xs.push_back(tx1);
      if(0<=tx2 && tx2<w) xs.push_back(tx2);
    }
  }

  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());

  rep(i, 0, n-1){
    x1[i] = find(all(xs), x1[i]) - xs.begin();
    x2[i] = find(all(xs), x2[i]) - xs.begin();
  }

  return xs.size();
}

int solve(vector<int> &x1, vector<int> &x2, vector<int> &y1, vector<int> &y2, int w, int h, int n){
  w = compress(x1, x2, w, n);
  h = compress(y1, y2, h, n);

  vector< vector<bool> > field(h, vector<bool>(w, false));
  rep(i, 0, n-1){
    rep(y, y1[i], y2[i]){
      rep(x, x1[i], x2[i]){
        field[y][x] = true;
      }
    }
  }

  /*
  cout << endl << "compressed field" << endl;
  rep(y, 0, h-1) {
    rep(x, 0, w-1){
      cout << (field[y][x]? "b " : ". ");
    }cout << endl;
  }cout << endl;
  */

  int ans = 0;
  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {-1, 1, 0, 0};
  rep(y, 0, h-1){
    rep(x, 0, w-1){
      if(field[y][x]) continue;
      ans++;

      queue<pii> que;
      que.push(pii(x, y));
      while(!que.empty()){
        pii p = que.front(); que.pop();

        rep(i, 0, 3){
          int nx = p.first + dx[i];
          int ny = p.second + dy[i];
          if(nx < 0 || nx >= w || ny < 0 || ny >= h || field[ny][nx]) continue;
          que.push(pii(nx, ny));
          field[ny][nx] = true;
        }
      }
    }
  }
  return ans;
}

/* ex data

30 12
10
2 8 10 12
4 2 8 10
2 0 10 2
12 2 14 10
14 10 18 12
14 0 18 4
18 2 20 10
22 0 28 2
24 2 26 10
22 10 28 12
0 0

*/

int main(){
  vector<int> ans(0);
  while(true){
    int w, h, n; cin >> w >> h;
    if(w == 0 && h == 0) break;
    cin >> n;
    vector<int> x1(n), x2(n), y1(n), y2(n);
    rep(i, 0, n-1) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    /*
    rep(i, 0, n-1){
      x1[i] *= 3;
      x2[i] *= 3;
      y1[i] *= 3;
      y2[i] *= 3;
    }
    w *= 3; h *= 3;
    */
    rep(i, 0, n-1) {
      x2[i]--; y2[i]--;
    }

    /*
    vector< vector<bool> > field(h, vector<bool>(w, false));
    rep(i, 0, n-1){
      rep(y, y1[i], y2[i]){
        rep(x, x1[i], x2[i]){
          field[y][x] = true;
        }
      }
    }

    cout << endl << "given field" << endl;
    rep(y, 0, h-1) {
      rep(x, 0, w-1){
        cout << (field[y][x]? "b " : ". ");
      }cout << endl;
    }cout << endl;
    */

    ans.push_back(solve(x1, x2, y1, y2, w, h, n));
  }

  for(auto v: ans) cout << v << endl;
}

