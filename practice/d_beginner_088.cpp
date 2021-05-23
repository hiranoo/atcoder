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
    int depth;
} P;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int h, w;
vector<vector<int>> area(52, vector<int>(52));
int INF = 3000;

void q_push(queue<P> &q, int x, int y, int d){
    P p = {x, y, d};
    q.push(p);
}

bool inside(int x, int y){
    if(0<=x && x<w && 0<=y && y<h && area.at(y).at(x)==0) return true;
    return false;
}

int search(){
    int depth = INF;

    queue<P> que;
    q_push(que, 0, 0, 0);

    while(que.size()){
        P p = que.front(); que.pop();
        int x = p.x;
        int y = p.y;
        int d = p.depth;

        if(x==w-1 && y==h-1){
            depth = d;
            break;
        }

        if(!inside(x, y)) continue;

        area.at(y).at(x) = -1;

        rep(i, 0, 3){
            int nx = x + dx[i];
            int ny = y + dy[i];
            q_push(que, nx, ny, d+1);
        }

    }

    return depth;
}

int main (){
    int original_insides = 0;
    cin >> h >> w;
    rep(y, 0, h-1){
        rep(x, 0, w-1){
            char buf; cin >> buf;
            if(buf == '.'){
                area.at(y).at(x) = 0;
                original_insides ++;
            }else{
                area.at(y).at(x) = -1;
            }
        }
    }

    int depth = search();
    //cout << "depth:" << depth << endl;
    int ans = original_insides-1 - depth;
    if(ans < 0) ans = -1;
    cout << ans << endl;
}