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

// global variables
int h, w, n;
vector<vector<int>> area(1001, vector<int>(1001));
vector<vector<int>> passed(1001, vector<int>(1001));
vector<vector<int>> start_point(12, vector<int>(2));

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// pre declare functions
void display(int sx, int sy, vector<vector<int>> area);
void clear(vector<vector<int>> &m){
    rep(y, 0, h-1){
        rep(x, 0, w-1){
            m.at(y).at(x) = 0;
        }
    }
}

bool inside(int x, int y, int vit){
    if(0<=x && x<w && 0<=y && y<h && 0<=area.at(y).at(x)) return true;
    return false;
}

void q_push(queue<P> &q, int x, int y, int d){
    P p = {x, y, d};
    q.push(p);
}

int bfs_search(int sx, int sy, int vit){
    if( !inside(sx, sy, vit) ) return 0;

    queue<P> que;
    q_push(que, sx, sy, 0);
    int tim = 0;

    while(que.size()){
        P p = que.front(); que.pop();
        int x = p.x;
        int y = p.y;
        int d = p.depth;

        //display(x, y, area);
        //cout << " x:" << x << " y:" << y << " d:" << d << " v:" << vit << endl;

        if( !inside(x, y, vit) ) continue;

        // 今いるマスの条件分岐
        if( area.at(y).at(x) == vit ) {
            tim = d;
            break;
        }
        if(passed.at(y).at(x) == 1){
            continue;
        }

        passed.at(y).at(x) = 1;

        // 隣接マスを探索（queueに追加）
        rep(i, 0, 3){
            int nx = x + dx[i];
            int ny = y + dy[i];
            q_push(que, nx, ny, d+1);
        }
    }

    return tim;
}


int main_search(int sx, int sy){
    int res = 0;
    int x = sx; int y = sy;
    rep(vit, 1, n){        
        // clear passed map
        clear(passed);

        // search
        int buf = bfs_search(x, y, vit);
        res += buf;
        
        // get next start point
        x = start_point.at(vit).at(0);
        y = start_point.at(vit).at(1);

        //cout << "vit: " << vit << " time:" << buf << endl;
        //display(x, y, passed);
    }
    return res;
}


int main(){
    //input
    int sx, sy;
    cin >> h >> w >> n;
    rep(y, 0, h-1){
        rep(x, 0, w-1){
            passed.at(y).at(x) = 0;
            char buf; cin >> buf;
            switch(buf){
                case 'S':
                    sx = x; sy = y;
                    area.at(y).at(x) = 0;
                    break;
                case '.':
                    area.at(y).at(x) = 0;
                    break;
                case 'X':
                    area.at(y).at(x) = -1;
                    break;
                default:
                    int num = buf - '0';
                    area.at(y).at(x) = num;
                    // remeber start points
                    start_point.at(num).at(0) = x;
                    start_point.at(num).at(1) = y;
                    break;
            }
        }
    }

    int ans = main_search(sx, sy);
    cout << ans << endl;

    return 0;
}



void display(int sx, int sy, vector<vector<int>> area){
    cout << "*** display ***" << endl;
    rep(y, 0, h-1){
        rep(x, 0, w-1){
            int a = area.at(y).at(x);
            if(sx==x && sy==y){
                cout << " P ";
            }else{
                if(a>=0)cout << ' ';
                cout << a << ' ';
            }
        }cout << endl;
    }cout << endl;
}
