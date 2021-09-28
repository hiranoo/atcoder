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

int h, w, sy, sx, gy, gx;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void display(vector<vector<int>> area){
    cout << "**** display ****" << endl;
    rep(y, 0, h-1){
        rep(x, 0, w-1){
            cout << area.at(y).at(x);
        }
        cout << endl;
    }cout << endl;
}
bool inside(int x, int y, vector<vector<int>> area){
    if( 0<=x && x<w && 0<=y && y<h && area.at(y).at(x)) return true;
    return false;
}

int search(vector<vector<int>> &area){
    queue<P> que;
    que.push(P({sx, sy, 0}));

    int cnt;
    while(que.size()){
        P p = que.front(); que.pop();
        int x = p.x;
        int y = p.y;
        int depth = p.depth;
        
        //cout << "x:" << x << " y:" << y << " cnt: " << cnt << endl;

        if(x==gx && y==gy){
            cnt = depth;
            break;
        }
        if(inside(x, y, area)){
            area.at(y).at(x) = 0;
            //display(area);
            rep(i, 0, 3){
                P push_p = {x+dx[i], y+dy[i], depth+1};
                que.push(push_p);
            }
        }
    }

    return cnt;
}

int main(){
    cin >> h >> w;
    cin >> sy >> sx; sy--; sx--;
    cin >> gy >> gx; gy--; gx--;
    vector<vector<int>> area(h, vector<int>(w));
    rep(y, 0, h-1){
        rep(x, 0, w-1){
            char buf;
            cin >> buf;
            area.at(y).at(x) = buf=='.' ? 1 : 0;
        }
    }

    int ans = search(area);
    cout << ans << endl;
}