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
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;

typedef struct{
    int x;
    int y;
    int vit;
} P;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int h, w;
int sx, sy, gx, gy;
vector<vector<int>> area(502, vector<int>(502));
vector<vector<int>> passed(502, vector<int>(502));

void display(int _x, int _y){
  cout << "*************" << endl;
  rep(y, 0, h-1){
    rep(x, 0, w-1){
      if(x==sx && y == sy) cout << ' ' << 's';
      else if(x==gx && y==gy) cout << ' ' << 'g';
      else if(x==_x && y==_y) cout << ' ' << 'p';
      else cout << ' ' << area.at(y).at(x);
    }cout << endl;
  }cout << endl;
}

void q_push(queue<P> &q, int x, int y, int b){
    P p = {x, y, b};
    q.push(p);
}

bool inside(int x, int y){
    if(0<=x && x<w && 0<=y && y<h && area.at(y).at(x) == 0) return true;
    return false;
}

bool wall(int x, int y){
    if(0<=x && x<w && 0<=y && y<h && area.at(y).at(x) == 1) return true;
    return false;
}

int search(){
    int res = -1;

    queue<P> que;
    q_push(que, sx, sy, 2);

    while(que.size()){
        P p = que.front(); que.pop();
        int x = p.x;
        int y = p.y;
        int v = p.vit;

        if(x==gx && y==gy){
            res = v;
            break;
        }

        if( !(inside(x, y) || wall(x, y)) ) continue;

        if(wall(x, y) && v > 0){
          if(passed.at(y).at(x) >= v) continue;
          passed.at(y).at(x) = v--;
          //display(x, y);
          rep(i, 0, 3){
            int nx = x + dx[i];
            int ny = y + dy[i];
            q_push(que, nx, ny, v);
            //cout << " nx:" << nx << " ny:" << ny << endl;
          }
        }   

        if(inside(x, y)){
          if(passed.at(y).at(x) >= v) continue;
          passed.at(y).at(x) = v;
          //display(x, y);
          rep(i, 0, 3){
            int nx = x + dx[i];
            int ny = y + dy[i];
            q_push(que, nx, ny, v);
            //cout << " nx:" << nx << " ny:" << ny << endl;
          }
        }

        //cout << "x:" << x << " y:" << y << " v:" << v << endl << endl;
    }

    return res;
}

int main (){
    cin >> h >> w;
    rep(y, 0, h-1){
      rep(x, 0, w-1){
        char buf; cin >> buf;
        switch(buf){
          case '#':
            area.at(y).at(x) = 1;
            break;
          case '.':
            area.at(y).at(x) = 0;
            break;
          case 's':
            area.at(y).at(x) = 0;
            sx = x; sy = y;
            break;
          case 'g':
            area.at(y).at(x) = 0;
            gx = x; gy = y;
            break;
        }
        passed.at(y).at(x) = -1;
      }
    }

    int ans = search();
    if(ans < 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}