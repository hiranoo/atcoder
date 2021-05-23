#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;

typedef pair<int, int> P;

int w, h;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

bool land(int x, int y, vector<vector<int>> area){
    if(0 <= x && x < w && 0 <= y && y < h && area.at(y).at(x)) return true;
    return false;
}

int search(int sx, int sy, vector<vector<int>> &area){
    if(!land(sx, sy, area)) return 0;

    stack<P> stk;
    stk.push(P(sx, sy));

    while(stk.size()){
        P p = stk.top(); stk.pop();
        int x = p.first;
        int y = p.second;

        if(!land(x, y, area)) continue;

        // only in land     
        area.at(y).at(x) = 0;

        rep(i, 0, 7){
            stk.push(P(x+dx[i], y+dy[i]));
        }

    }

    return 1;
}

int main_loop(){
    cin >> w >> h;
    vector<vector<int>> area(h, vector<int>(w));
    rep(y, 0, h-1){
        rep(x, 0, w-1){
            cin >> area.at(y).at(x);
        }
    }

    if(w == 0 && h == 0) return -1;

    int ans = 0;
    rep(y, 0, h-1){
        rep(x, 0, w-1){
            ans += search(x, y, area);
        }
    }

    return ans;
}

int main(){
    vector<int> ans;
    int res = 0;
    while(res >= 0){
        res = main_loop();
        if(res == -1) break;
        ans.push_back(res);
    }

    rep(i, 0, ans.size()-1){
        cout << ans.at(i) << endl;
    }

    return 0;
}