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
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

#define MAX_H 501
#define MAX_W 501

vector<string> c(0);
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int h, w, sx, sy, gx, gy;

void display(){
    cout << endl << "-------------" << endl;
    for(int k  = 0; k < h; k++) cout << c[k] << endl;
}
    

bool inside(int x, int y){
    if(0<=x && x<w && 0<=y && y<h && c[y][x]!='#')return true;
    return false;
}

bool dfs(int x, int y){
    //display();
    if(x == gx && y==gy) return true;
    c[y][x] = '#'; 
    rep(i, 0, 3){
        int nx = x+dx[i]; int ny = y + dy[i];
        if(inside(nx, ny) && dfs(nx, ny)) return true;
    }
    return false;
}

bool dfs_stack(int _x, int _y){
    stack<P> stk;
    stk.push(P(_x, _y));
    while(stk.size()){
        P p = stk.top(); stk.pop();
        int x = p.first; int y = p.second;
        if(x==gx && y==gy) return true;
        c[y][x] = '#';
        rep(i, 0, 3){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(inside(nx, ny)) stk.push(P(nx, ny));
        }
    }
    return false;
}

int main(){
    cin >> h >> w;
    rep(y, 0, h-1){
        string s; cin >> s;
        c.push_back(s);
        rep(x, 0, w-1){
            switch(s[x]){
                case 's':
                    sx = x; sy = y;
                    break;
                case 'g':
                    gx = x; gy = y;
                    break;
                default:
                    break;
            }
        }
    }

    bool ans = dfs_stack(sx, sy);
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
